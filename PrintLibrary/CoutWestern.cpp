//Encoding=WestEuropean - 1252
#include <iostream>
#include "Convert.h"

void printCoutWestern() {
    char* unicode_msg = "αινσϊ";
    std::cout << "Western/Latin1/ISO8859 File - COUT CHAR*: " << unicode_msg << std::endl;
    std::wcout << "Western/Latin1/ISO8859 File - WCOUT CHAR*: " << unicode_msg << std::endl;

	wchar_t* unicode_msg_w = L"αινσϊ";
	std::cout << "Western/Latin1/ISO8859 File - COUT WCHAR_T*: " << unicode_msg_w << std::endl;
	std::wcout << "Western/Latin1/ISO8859 File - WCOUT WCHAR_T*: " << unicode_msg_w << std::endl;

    std::cout << "Western/Latin1/ISO8859 File - Converted - Utf16toUtf8: " << Utf16ToUtf8(unicode_msg_w);
    std::wcout << L" - Utf8toUtf16: " << Utf8ToUtf16(unicode_msg) << std::endl;
}