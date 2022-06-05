#include "file.h"

#include <iostream>
#include <string>
#include <fstream>

namespace Pdflib
{
    class Decoder
    {
    public:
        Decoder();
        Decoder(const std::string& file);
        ~Decoder();

        void openFile(const std::string& file);
        void closeFile();

        bool isFilePresent(const std::string& name);
    private:
        DecoderFile mOpenedFile { };
    };
}