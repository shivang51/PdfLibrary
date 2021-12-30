#include <iostream>
#include "PDFDecoder.h"

int main() {
	std::string file = "D:\\C++\\Projects\\PdfLibrary\\Files\\ex1.pdf";

	PdfLib::Decoder decoder;

	auto err = decoder.OpenFile(file);
	if ( err != PdfLib::Error::None )
	{
		std::cout << "File Not Found: " << file << std::endl;
		return -1;
	}

	auto catalog = decoder.GetCatalog();
	auto pages = decoder.GetPagesDictionary(catalog);

	std::cout << pages.Count << std::endl;

	decoder.CloseCurrentFile();

	return 0;
}