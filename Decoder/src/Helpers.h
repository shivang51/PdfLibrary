#pragma once

#include <string>
#include <sstream>
#include <vector>

namespace PdfLib
{
    namespace Helpers
    {
        /**
        * Converts a string number to integer e.g. "40" to 40
        * @param str String which you want to convert
        * @returns String which you passed as Integer
        **/
        int StrToInt(std::string& str);

        /**
        * Converts a single ascii value to character
        * @param ascii Value as int e.g. 65
        * @returns Character from ascii value
        **/
        char AsciiToChar(int ascii);

        /**
        * Converts a single ascii value to character
        * @param ascii Value as String e.g. '65'
        * @returns Character from ascii value
        **/
        char AsciiToChar(std::string& ascii);

        /**
        * Converts Hex to String
        * @param hex Number in hex notation e.g. 0x20
        * @returns hex as string which contains single character
        **/
        std::string hex2chr(int hex);

        /**
        * Converts Hex to String
        * @param hex Number not in hex notaion e.g 20
        * @returns hex as string which contains single character
        **/
        std::string hex2chr(std::string& hex);

        /**
        * Converts String to ascii values
        * @param string to get ascii values
        * @returns int vector containg ascii values
        **/
        std::vector<int> string2ascii(const std::string& s);

        std::vector<std::string> SplitString(std::string& s, std::string splitValue);

        void StringReplaceAll(std::string& str, const std::string& from, const std::string& to);
        void StringReplace(std::string& str, const std::string& from, const std::string& to);
        void StringReplaceEnd(std::string& str, const std::string& from, const std::string& to);

    }

}