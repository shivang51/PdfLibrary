#include "pdflib/pdflib.h"

#include <string>

int main() {
	std::string file = "D:\\C++\\Projects\\PdfLibrary\\files\\ex2.pdf";

	Pdflib::Decoder decoder;

	decoder.openFile(file);

	return 0;
}