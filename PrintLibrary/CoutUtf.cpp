//Encoding=UTF8
#include <iostream>
#include "Convert.h"

void printCoutUtf() {
    char* unicode_msg = "áéíóú";
    std::cout << "UTF8 File - COUT CHAR*: " << unicode_msg << std::endl;
    std::wcout << "UTF8 File - WCOUT CHAR*: " << unicode_msg << std::endl;

	wchar_t* unicode_msg_w = L"áéíóú";
	std::cout << "UTF8 File - COUT WCHAR_T*: " << unicode_msg_w << std::endl;
    std::wcout << "UTF8 File - WCOUT WCHAR_T*: " << unicode_msg_w << std::endl;
    
    std::cout << "UTF8 File - Converted - Utf16toUtf8: " << Utf16ToUtf8(unicode_msg_w);
    std::wcout << L" - Utf8toUtf16: " << Utf8ToUtf16(unicode_msg) << std::endl;
}