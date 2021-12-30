#include "String.h"

namespace PdfLib::DataType
{
    String::String()
    {
        this->str = "";
    }

    String::String(const char* str)
    {
        this->str = std::string(str);
    }

    String::String(const std::string& str)
    {
        this->str = str;
    }

    String::String(const String& str)
    {
        this->str = str.StdStr();
    }

    String String::Reverse()
    {
        return std::string(this->str.rbegin(), this->str.rend());
    }

    void String::Reverseo()
    {
        this->str = std::string(this->str.rbegin(), this->str.rend());
    }

    size_t String::Length()
    {
        return this->str.size();
    }

    const std::string String::StdStr() const
    {
        return  this->str;
    }

    const char* String::CStr()
    {
        return this->str.c_str();
    }

    std::vector<String> String::Split(const char& ch)
    {
        std::vector<String> arr;
        std::string word = "";
        for ( auto c : this->str )
        {
            if ( c == ch )
            {
                arr.push_back(word);
                word = "";
            }
            else
            {
                word.push_back(c);
            }
        }
        arr.push_back(word);
        return arr;
    }

    std::vector<String> String::Split(const std::string& split_str)
    {
        std::vector<String> stringarr = { };
        int start = 0;
        int end = str.find(split_str);
        size_t size = split_str.size();
        while ( end != -1 )
        {
            stringarr.push_back(str.substr(start, end - start));
            start = end + size;
            end = str.find(split_str, start);
        }
        if ( start != str.size() )
        stringarr.push_back(str.substr(start, str.size()-1));

        return stringarr;
    }

    std::vector<String> String::Split(const char* split_str)
    {
        return Split(std::string(split_str));
    }

    void String::ReplaceAll(const std::string& from, const std::string& to)
    {
        if ( from.empty() )
            return;
        size_t start_pos = 0;
        while ( ( start_pos = str.find(from, start_pos) ) != std::string::npos )
        {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
    }

    void String::Replace(const std::string& from, const std::string& to)
    {
        size_t start_pos = str.find(from);
        if ( start_pos == std::string::npos )
            return;
        str.replace(start_pos, from.length(), to);
    }

    void String::ReplaceEnd(const std::string& from, const std::string& to)
    {
        size_t start_pos = str.find_last_of(from);
        if ( start_pos == std::string::npos )
            return;
        str.replace(start_pos - from.length() + 1, from.length(), to);
    }

    bool String::Contains(const std::string& str)
    {
        return this->str.find(str) != std::string::npos;
    }

    bool String::Contains(const String& str)
    {
        return this->str.find(str.StdStr()) != std::string::npos;
    }

    bool String::Contains(const char& chr)
    {
        return this->str.find(chr) != std::string::npos;;
    }

    void String::Strip()
    {
        std::vector<std::string> chars = { "\n", " " };
        auto st = String(str);
        for ( auto& ch : chars )
        {
            if(st.StartsWith(ch))
            this->Replace(ch, "");
            else if(st.EndsWith(ch) )
            this->ReplaceEnd(ch, "");
        }
    }

    bool String::StartsWith(const String& check_str)
    {
        return this->str._Starts_with(check_str.StdStr());
    }

    bool String::EndsWith(const String& check_str)
    {
        return this->str.substr(this->Length() - check_str.StdStr().size()) == check_str;
    }

    int String::ToInt()
    {
        return std::stoi(this->str);
    }

    std::vector<String> String::ToVector()
    {

        auto str1 = String(this->str);
        str1.Strip();
        if ( !str1.StartsWith("[") || !str1.EndsWith("]") )
            return std::vector<String>({this->str});

        str1.Replace("[", "");
        str1.ReplaceEnd("]", "");

        std::vector<String> arr = { };

        for ( auto& el : str1.Split(" R") )
        {
            el.Strip();
            arr.push_back(el + " R");
        }

        return arr;
    }

    void String::Clear()
    {
        this->str.clear();
    }

    bool operator==(const String& one, const String& two)
    {
        return one.StdStr() == two.StdStr();
    }

    String operator+(const String& one, const String& two)
    {
        return one.StdStr() + two.StdStr();
    }

    String::~String()
    {
        this->str.clear();
    }
}