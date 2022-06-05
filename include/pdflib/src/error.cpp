#include "error.h"


namespace Pdflib
{
    Error::Error(const std::string& msg, const ErrorType type)
    {
        mMsg = msg;
        mType = type;
    }
}
