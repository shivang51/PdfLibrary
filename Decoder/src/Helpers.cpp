#include "Helpers.h"

namespace PdfLib
{
    int Helpers::StrToInt(std::string& str)
    {
        std::stringstream ss;
        if ( str.substr(0, 2) == "0x" )
        {
            ss << std::hex;
        }
        ss << str;
        int n;
        ss >> n;
        return n;
    }

    char Helpers::AsciiToChar(int ascii)
    {
        return (char) ascii;
    }

    char Helpers::AsciiToChar(std::string& ascii)
    {
        return (char) Helpers::StrToInt(ascii);
    }

    std::string Helpers::hex2chr(int hex)
    {
        return std::string(1, Helpers::AsciiToChar(hex));
    }

    std::string Helpers::hex2chr(std::string& hex)
    {
        if ( hex.substr(0,2) != "0x" )
        hex = "0x" + hex;
        int n = Helpers::StrToInt(hex);
        return Helpers::hex2chr(n);
    }

    std::vector<int> Helpers::string2ascii(const std::string& s)
    {
        std::vector<int> result;

        for ( std::size_t i = 0; i <= s.size() / 2; i++ )
            result.push_back((int)s[i]);

        return result;
    }
    
    std::vector<std::string> Helpers::SplitString(std::string& s, std::string splitValue)
    {
        std::vector<std::string> stringarr = { };
        int start = 0;
        int end = s.find(splitValue);
        size_t size = splitValue.size();
        while ( end != -1 )
        {
            stringarr.push_back(s.substr(start, end - start));
            start = end + size;
            end = s.find(splitValue, start);
        }
        stringarr.push_back(s.substr(start, end - start));

        return stringarr;
    }

    void Helpers::StringReplaceAll(std::string& str, const std::string& from, const std::string& to)
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

    void Helpers::StringReplace(std::string& str, const std::string& from, const std::string& to)
    {
        size_t start_pos = str.find(from);
        if ( start_pos == std::string::npos )
            return;
        str.replace(start_pos, from.length(), to);
    }
    
    void Helpers::StringReplaceEnd(std::string& str, const std::string& from, const std::string& to)
    {
        size_t start_pos = str.find_last_of(from);
        if ( start_pos == std::string::npos )
            return;
        str.replace(start_pos, from.length(), to);
    }
}