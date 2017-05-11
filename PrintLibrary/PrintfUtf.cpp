//Encoding=UTF8
#include <stdio.h>
#include<windows.h>

void printPrintfUtf() {
	SetConsoleOutputCP(CP_UTF8);

    const char* unicode_msg = "áéíóú";
    const wchar_t* unicode_msg_w = L"áéíóú";
    printf("UTF8 File - PRINTF: %s - LEN: %d\n", unicode_msg, strlen(unicode_msg));
    printf("UTF8 File - PRINTF wide: %S- LEN: %d\n", unicode_msg_w, wcslen(unicode_msg_w));

}