#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace PdfLib
{
    enum class Error
    {
        None = 0,
        Unknown,
        NotFound
    };

    enum class NumberingStyle
    {
        None = -1,
        Decimal = 0,
        UppercaseRoman,
        LowercaseRoman,
        UppercaseLetters,
        LowercaseLetters,
    };

    enum class PageMode
    {
        UseNone = 0,
        UseOutlines,
        UseThumbs,
        UseOC,
        UseAttachments,
        FullScreen
    };

    enum class PageLayout
    {
        SinglePage = 0,
        TwoColumn,
        TwoColumnLeft,
        TwoColumnRight,
        TwoPagesLeft,
        TwoPagesRight,
    };

    enum class Direction
    {
        L2R = 0,
        R2L,
        None
    };
}

namespace PdfLib
{
    struct File
    {
        std::string location = "";
        bool open = false;
        std::ifstream fileStream = std::ifstream();
        size_t length = 0;
    };

    struct FindError
    {
        Error error = Error::None;
        int start = -1;
        size_t size = 0;
    };
}
