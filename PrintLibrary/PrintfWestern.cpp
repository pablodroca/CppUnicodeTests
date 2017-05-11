//Encoding=WestEuropean - 1252
#include <stdio.h>
#include<windows.h>

void printPrintfWestern() {
	SetConsoleOutputCP(1252);

    const char* unicode_msg = "αινσϊ";
    const wchar_t* unicode_msg_w = L"αινσϊ";
    printf("Western/Latin1/ISO8859 File - PRINTF: %s - LEN: %d\n", unicode_msg, strlen(unicode_msg));
    printf("Western/Latin1/ISO8859 File - PRINTF wide: %S- LEN: %d\n", unicode_msg_w, wcslen(unicode_msg_w));

}