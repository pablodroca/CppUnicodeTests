#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>
#include <string>

#include "../PrintLibrary/Convert.h"

#define CHAR_FILE "char.txt"
#define WCHAR_FILE "wchar.txt"

void printCoutWestern();
void printCoutUtf();
void printPrintfWestern();
void printPrintfUtf();



int wmain(int argc, wchar_t* argv[])
{
    if (argc > 1) {
        std::stringstream ss;
        std::wstringstream wss;
        ComputeConvertionsInfo(argv[1], ss, wss);

        std::cout << "Storing to file: '" << CHAR_FILE << "' TEXT:" << std::endl << ss.str() << std::endl << std::endl;
        std::ofstream char_file(CHAR_FILE);
        char_file << ss.str();
        char_file.close();

        std::wcout << L"Storing to file: '" << WCHAR_FILE << L"' TEXT:" << std::endl << wss.str() << std::endl << std::endl;
        std::wofstream wchar_file(WCHAR_FILE);
        wchar_file << wss.str();
        wchar_file.close();

    }

    printPrintfUtf();
    printCoutUtf();
    std::cout << std::endl;
    printPrintfWestern();
    printCoutWestern();

    std::cout << std::endl << "Program finished. Enter any key to continue..." << std::endl;
    int c = getchar();

    return 0;
}

