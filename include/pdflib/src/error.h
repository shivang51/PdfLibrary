#include <string>

namespace Pdflib
{
    enum class ErrorType
    {
        unknown = -1,
        none,
        fileNotFound
    };

    class Error
    {
    private:
        std::string mMsg = "";
        ErrorType mType = ErrorType::none;
    public:
        Error(const std::string& msg, const ErrorType type);
        const std::string& message = mMsg;
        const ErrorType& errorType = mType;
    };
}