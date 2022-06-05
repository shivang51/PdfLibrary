#include "file.h"

namespace Pdflib
{
    DecoderFile::DecoderFile()
    {}

    DecoderFile::DecoderFile(const std::string& path)
    {
        this->open(path);
    }

    DecoderFile::~DecoderFile()
    {
        this->close();
    }

    void DecoderFile::open(const std::string& path)
    {
        mPath = path;
        mHandle = std::ifstream(path);
    }

    void DecoderFile::close()
    {
        mHandle.close();
        mPath = "";
    }

    std::string DecoderFile::getName()
    {
        return mPath.substr(mPath.find_last_of("\\") + 1);
    }

    std::string& DecoderFile::getPath()
    {
        return mPath;
    }

    std::ifstream& DecoderFile::getHandle()
    {
        return mHandle;
    }

    std::ifstream* DecoderFile::operator->()
    {
        return &mHandle;
    }


}