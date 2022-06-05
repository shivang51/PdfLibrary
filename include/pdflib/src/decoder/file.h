#include <string>
#include <fstream>

namespace Pdflib
{
    class DecoderFile
    {
    private:
        std::string mPath = "";
        std::ifstream mHandle = std::ifstream();

    public:
        DecoderFile();
        DecoderFile(const std::string& path);
        ~DecoderFile();
        void open(const std::string& path);
        void close();

        std::string getName();
        std::string& getPath();
        std::ifstream& getHandle();

        std::ifstream* operator->();
    };
}