//Based on https://msdn.microsoft.com/en-us/magazine/mt763237.aspx from  giovanni.dicanio@gmail.com.
#include <string>
#include <sstream>
#include <windows.h>
#include "Convert.h"

#define CP_LATIN1 1252


void ComputeConvertionsInfo(const std::string& text, std::stringstream& ss, std::wstringstream& wss) {
    ss << "TEXT CHAR*: '" << text.c_str() << "' - LEN: " << strlen(text.c_str()) << std::endl;
    ss << "TEXT std::string: '" << text << "' - LEN: " << text.length() << " - SIZE: " << text.size() << std::endl;

    std::wstring text_converted = Utf8ToUtf16(text);
    wss << "TEXT WCHAR_T*: '" << text_converted.c_str() << "' - LEN: " << wcslen(text_converted.c_str()) << std::endl;
    wss << "TEXT std::wstring: '" << text_converted << L"' - LEN: " << text_converted.length() << " - SIZE: " << text_converted.size() << std::endl;
}

void ComputeConvertionsInfo(const std::wstring& text, std::stringstream& ss, std::wstringstream& wss) {
    std::string text_converted = Utf16ToUtf8(text);
    ComputeConvertionsInfo(text_converted, ss, wss);
}

std::wstring Utf8ToUtf16(const std::string& utf8) {
    std::wstring utf16;
    if (! utf8.empty()) {
        const DWORD kFlags = MB_ERR_INVALID_CHARS;
        const int utf8Length = static_cast<int>(utf8.length());
        const int utf16Length = ::MultiByteToWideChar(
            CP_UTF8,       // Source string is in UTF-8
            kFlags,        // Conversion flags
            utf8.data(),   // Source UTF-8 string pointer
            utf8Length,    // Length of the source UTF-8 string, in chars
            nullptr,       // Unused - no conversion done in this step
            0              // Request size of destination buffer, in wchar_ts
        );
        if (utf16Length > 0) {
            utf16.resize(utf16Length);
            ::MultiByteToWideChar(
                CP_UTF8,       // Source string is in UTF-8
                kFlags,        // Conversion flags
                utf8.data(),   // Source UTF-8 string pointer
                utf8Length,    // Length of source UTF-8 string, in chars
                &utf16[0],     // Pointer to destination buffer
                utf16Length    // Size of destination buffer, in wchar_ts          
            );
        }
	}
    return utf16;
}


std::string Utf16ToUtf8(const std::wstring& utf16) {
    std::string utf8;
    if (!utf16.empty()) {
        const DWORD kFlags = MB_ERR_INVALID_CHARS;
        const int utf16Length = static_cast<int>(utf16.length());
        const int utf8Length = ::WideCharToMultiByte(
            CP_UTF8,       // Source string is in UTF-8
            kFlags,        // Conversion flags
            utf16.data(),   // Source UTF-8 string pointer
            utf16Length,    // Length of the source UTF-8 string, in chars
            nullptr,       // Unused - no conversion done in this step
            0,             // Request size of destination buffer, in wchar_ts
            nullptr,
            nullptr);
        if (utf8Length > 0) {
            utf8.resize(utf8Length);
            ::WideCharToMultiByte(
                CP_LATIN1,       // Source string is in UTF-8
                kFlags,        // Conversion flags
                utf16.data(),   // Source UTF-8 string pointer
                utf16Length,    // Length of source UTF-8 string, in chars
                &utf8[0],     // Pointer to destination buffer
                utf8Length,    // Size of destination buffer, in wchar_ts          
                nullptr,
                nullptr
            );
        }
    }
    return utf8;
}
