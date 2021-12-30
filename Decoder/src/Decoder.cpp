#include "Decoder.h"

namespace PdfLib
{
    Decoder::Decoder()
    {
    }

    Decoder::~Decoder()
    {
        this->CloseCurrentFile();
    }

    Error Decoder::OpenFile(std::string& filelocation)
    {
        this->CloseCurrentFile();

        try
        {
            if ( !this->FileExist(filelocation) )
            {
                return Error::NotFound;
            }
            this->mainFile.location = filelocation;
            this->mainFile.fileStream = std::ifstream(filelocation, std::ios_base::binary);
            this->mainFile.open = true;
            this->mainFile.fileStream.seekg(0, std::ios::end);
            this->mainFile.length = (size_t) this->mainFile.fileStream.tellg();
            this->mainFile.fileStream.seekg(0, std::ios::beg);

        }
        catch ( int )
        {
            return Error::Unknown;
        }

        return Error::None;
    }

    Error Decoder::CloseCurrentFile()
    {
        if ( this->mainFile.open )
        {
            this->mainFile.fileStream.close();
            this->mainFile = File();
        }
        return Error::None;
    }

    inline bool Decoder::FileExist(const std::string& name)
    {
        struct stat buffer;
        return ( stat(name.c_str(), &buffer) == 0 );
    }

    FindError Decoder::FindString(const std::string& str, const bool equal)
    {
        this->mainFile.fileStream.clear();
        this->mainFile.fileStream.seekg(0, this->mainFile.fileStream.beg);
        std::string line;
        int n = 0;

        while ( std::getline(this->mainFile.fileStream, line) )
        {
            if ( str.size() <= line.size() )
            {
                if ( equal && line == str)
                {
                    return FindError(Error::None, n);
                }
                else if ( !equal && line.find(str) != std::string::npos )
                {
                    return FindError(Error::None, n);
                }
            }
            line.clear();
            n = (int) this->mainFile.fileStream.tellg();
        }

        return FindError(Error::NotFound, -1);
    }


    FindError Decoder::FindDictionary(const std::string& type)
    {

        auto value = this->FindString("/Type /" + type);

        if ( value.error == Error::NotFound )
        {
            value = this->FindString("/Type/" + type);
        }

        int start = value.start + 4;
        std::string temp;
        size_t size = 1;

        while ( start >= 0 )
        {
            this->mainFile.fileStream.seekg(std::ios::beg + start);
            this->mainFile.fileStream.read(temp.data(), 2);

            if ( strcmp(temp.c_str(), "<<") == 0 )
            {
                break;
            }

            start--;
        }

        this->mainFile.fileStream.seekg(std::ios::beg + start + size);
        while ( this->mainFile.fileStream.read(temp.data(), 2) )
        {
            if ( strcmp(temp.c_str(), ">>") == 0 )
            {
                return FindError(Error::None, start, size + 1);
            }
            this->mainFile.fileStream.seekg(std::ios::beg + start + size);
            size++;
        }

        return FindError(Error::NotFound, start, -1);
    }


    FindError Decoder::FindObject(DataType::String& name)
    {
        name.Replace(" R", " obj");
        auto loc = this->FindString(name.StdStr(), true);

        if ( loc.error != Error::None )
        {
            return loc;
        }

        auto objLoc = FindError();
        auto start = loc.start + name.Length();
        objLoc.start = (int)start;
        std::string temp = "";
        std::string temp1 = "";
        this->mainFile.fileStream.clear();
        this->mainFile.fileStream.seekg(std::ios::beg + start);

        int openCount = 0;

        while ( openCount != 0 || objLoc.size < 4 )
        {
            this->mainFile.fileStream.read(temp.data(), 1);

            temp1 = temp1 + std::string(temp.data());
            if ( temp1.size() > 2 )
            {
                temp1 = temp1.substr(1, 2);
            }

            objLoc.size += 1;

            if ( temp1 == "<<" )
                openCount += 1;
            else if ( temp1 == ">>" )
                openCount -= 1;
        }
        objLoc.error = Error::None;
        return objLoc;
    }

    DataType::Dictionary::Dictionary<DataType::String, DataType::String> Decoder::ParseObject(DataType::String& obj)
    {
        DataType::Dictionary::Entry<DataType::String, DataType::String> entery;
        DataType::Dictionary::Dictionary<DataType::String, DataType::String> dict;

        obj.ReplaceAll("\n", "");
        obj.ReplaceAll("<<", "");
        obj.ReplaceAll(" /", "/");

        DataType::String breakChars = " /", spcBreakChars = "[(";


        bool rKey = true;
        auto str = obj.StdStr();
        str = str.substr(str.find_first_of('/') + 1);
        obj = str;
        str.clear();

        for ( auto ch : obj.StdStr() )
        {
            if ( ch == '>' )
            {
                entery.SetValue(str);
                dict.AddEntry(entery);
                break;
            }
            else if ( ( breakChars.Contains(ch) || spcBreakChars.Contains(ch) ) && rKey )
            {
                rKey = false;
                entery.SetKey(str);
                str = "";
                if ( !spcBreakChars.Contains(ch) )
                    continue;
            }
            else if ( ch == '/' && !rKey )
            {
                rKey = true;
                entery.SetValue(str);
                str = "";
                dict.AddEntry(entery);
                continue;
            }
            str += ch;
        }
        return dict;
    }

    DataType::String Decoder::GetData(int start, size_t size)
    {
        std::string buffer;
        buffer.resize(size);
        this->mainFile.fileStream.clear();
        this->mainFile.fileStream.seekg(std::ios::beg + start);
        this->mainFile.fileStream.read(buffer.data(), size);
        return buffer;
    }

    Objects::Catalog Decoder::GetCatalog()
    {
        Objects::Catalog catalog = Objects::Catalog();

        //Catalog Dictionary
        auto dataLoc = this->FindDictionary("Catalog");
        if ( dataLoc.error != Error::None )
            return catalog;
        auto dataBuff = this->GetData(dataLoc.start, dataLoc.size);
        auto catalogDict = ParseObject(dataBuff);

        //Pages Dictionary
        if ( catalogDict.KeyExsist("Pages") )
        {
            catalog.Pages = catalogDict.GetValue("Pages");
        }

        return catalog;
    }
    Objects::PagesDict Decoder::GetPagesDictionary()
    {
        auto catalog = GetCatalog();
        return GetPagesDictionary(catalog);
    }
    Objects::PagesDict Decoder::GetPagesDictionary(Objects::Catalog& catalog)
    {
        if ( catalog.Pages != "" )
        {
            auto dataLoc = this->FindObject(catalog.Pages);
            if ( dataLoc.error != Error::None )
                return Objects::PagesDict();

            auto pagesDict = Objects::PagesDict();
            auto dataBuff = this->GetData(dataLoc.start, dataLoc.size);
            auto pagesObj = this->ParseObject(dataBuff);
            pagesDict.Count = pagesObj.GetValue("Count").ToInt();
            pagesDict.Kids = pagesObj.GetValue("Kids").ToVector();
            return pagesDict;
        }
        return Objects::PagesDict();
    }
}

