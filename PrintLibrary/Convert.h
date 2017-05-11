#ifndef __convert__h
#define __convert__h

#include <string>
#include <sstream>
void ComputeConvertionsInfo(const std::string& text, std::stringstream& ss, std::wstringstream& wss);
void ComputeConvertionsInfo(const std::wstring& text, std::stringstream& ss, std::wstringstream& wss);
std::wstring Utf8ToUtf16(const std::string& utf8);
std::string Utf16ToUtf8(const std::wstring& utf16);

#endif
