#include "decoder.h"

#include "pdflib/src/error.h"

#include <format>
#include <iostream>

namespace Pdflib
{
    Decoder::Decoder()
    {}

    Decoder::Decoder(const std::string & file)
    {
        this->openFile(file);
    }

    Decoder::~Decoder()
    {
        this->closeFile();
    }

    bool Decoder::isFilePresent(const std::string& name)
    {
        struct stat buffer;
        return ( stat(name.c_str(), &buffer) == 0 );
    }

    void Decoder::openFile(const std::string& file)
    {
        if ( !isFilePresent(file) )
            throw Error(std::format("file not found at {}", file), ErrorType::fileNotFound);

        mOpenedFile.open(file);
        std::cout << mOpenedFile.getName() << std::endl;
        std::string s;
        std::getline(mOpenedFile.getHandle(), s);
        std::cout << s << std::endl;
        
    }

    void Decoder::closeFile()
    {
        mOpenedFile.close();
    }
}
