#pragma once

#include "Types.h"
#include "DataTypes.h"

namespace PdfLib
{
    namespace Objects
    {
        typedef DataType::String Reference;

        struct PageLabelDict
        {
            DataType::String Type = "PageLable";
            NumberingStyle S = NumberingStyle::None;
            DataType::String P = "";
            int St = 1;
        };

        typedef DataType::Dictionary::Dictionary<int, PageLabelDict> PageLabelsDict;

        struct DeveloperExtDict
        {
            DataType::String Type = "DeveloperExtensions";
            float BaseVersion = 0.0f;
            int ExtensionVerson = 0;
        };

        typedef DataType::Dictionary::Dictionary<DataType::String, DeveloperExtDict> ExtensionsDict;

        struct PagesDict
        {
            DataType::String Type = "Pages";
            DataType::String Parent = DataType::String();
            std::vector<DataType::String> Kids = { };
            int Count = 0;
        };

        struct NamesDict
        {
            DataType::String Dests = DataType::String();
            DataType::String AP = DataType::String();
            DataType::String JavaScript = DataType::String();
            DataType::String Pages = DataType::String();
            DataType::String Templates = DataType::String();
            DataType::String IDS = DataType::String();
            DataType::String URLS = DataType::String();
            DataType::String EmbededFiles = DataType::String();
            DataType::String AlternatePresentaions = DataType::String();
            DataType::String Renditions = DataType::String();
        };

        struct ViewerPrefrencesDict
        {
            bool HideToolbar = false;
            bool HideMenubar = false;
            bool HideWindowUI = false;
            bool HideFitWindow = false;
            bool CenterWindow = false;
            bool DisplayDocTile = false;
            PageMode NonFullScreenPageMode = PageMode::UseNone;
            Direction Direction = Direction::None;
            DataType::String ViewArea = "";
        };

        struct Catalog
        {
            DataType::String Type = "Catalog";
            DataType::String Version = "";
            ExtensionsDict Extensions = ExtensionsDict();
            Reference Pages = Reference();
            PageLabelsDict PageLables = PageLabelsDict();
            NamesDict Names = NamesDict();
            DataType::String Dests = DataType::String();
            ViewerPrefrencesDict ViewPrefrences = ViewerPrefrencesDict();
            PageLayout PageLayout = PageLayout::SinglePage;
            PageMode PageMode = PageMode::UseNone;
            DataType::String Outlines = DataType::String();
        };
    }
}
