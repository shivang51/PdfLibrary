#pragma once

#include <string>
#include <vector>

namespace PdfLib::DataType
{
    class String
    {
    public:
        String();
        String(const char* str);
        String(const std::string& str);
        String(const String& str);
        ~String();

        /**
        * Returns copy of string reversed.
        **/
        String Reverse();

        /**
        * Reverses the original string.
        **/
        void Reverseo();

        /**
        * Returns length of string.
        **/
        size_t Length();

        /**
        * Returns std::string object of string.
        **/
        const std::string StdStr() const;

        /**
        * Returns string as char array.
        **/
        const char* CStr();

        /**
        * Splits the string.
        * @param ch - char with which string is split.
        * @return vector containg split string
        **/
        std::vector<String> Split(const char& ch);
        /**
        * Splits the string.
        * @param split_str - string with which string is split.
        * @return vector containg split string
        **/
        std::vector<String> Split(const std::string& split_str);
        /**
        * Splits the string.
        * @param split_str - string with which string is split.
        * @return vector containg split string
        **/
        std::vector<String> Split(const char* split_str);

        /**
        * Replace first occurance of given string.
        * @param from - Value to be replaced.
        * @param to - Value with which it should be replaced.
        **/
        void Replace(const std::string& from, const std::string& to);
        /**
        * Replace all occurances of given string.
        * @param from - Value to be replaced.
        * @param to - Value with which it should be replaced.
        **/
        void ReplaceAll(const std::string& from, const std::string& to);
        /**
        * Replace last occurance of given string.
        * @param from - Value to be replaced.
        * @param to - Value with which it should be replaced.
        **/
        void ReplaceEnd(const std::string& from, const std::string& to);

        /**
        Checks if given string is their or not.
        **/
        bool Contains(const std::string& str);
        /**
        * Checks if given string is their or not.
        **/
        bool Contains(const String& str);
        /**
        * Checks if given string is their or not.
        **/
        bool Contains(const char& chr);

        /**
            Removes spaces and new line characters from begening and at the end.
        **/
        void Strip();

        bool StartsWith(const String& check_str);

        bool EndsWith(const String& check_str);

        int ToInt();

        std::vector<String> ToVector();

        void Clear();
    private:
        std::string str = "";
        friend bool operator==(const String& one, const String& two);
        friend String operator+(const String& one, const String& two);
    };
}
