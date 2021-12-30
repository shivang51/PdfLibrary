#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Types.h"
#include "Helpers.h"
#include "Objects.h"
#include "DataTypes.h"
namespace PdfLib
{
    class Decoder
    {
    public:
        Decoder();
        ~Decoder();

    public:
        Error OpenFile(std::string &filelocation);
        Error CloseCurrentFile();
        Objects::Catalog GetCatalog();
        Objects::PagesDict GetPagesDictionary();
        Objects::PagesDict GetPagesDictionary(Objects::Catalog& catalog);

    private:
        File mainFile = File();

    private:

        inline bool FileExist(const std::string& name);
        FindError FindString(const std::string& str, const bool equal = false);
        FindError FindDictionary(const std::string& type);
        FindError FindObject(DataType::String& name); 
        DataType::Dictionary::Dictionary<DataType::String, DataType::String> ParseObject(DataType::String& obj);
        DataType::String GetData(int start, size_t size);

    };
};