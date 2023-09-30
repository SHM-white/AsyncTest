#include "include.h"

std::string ToolFunctions::wstringToU8string(const std::wstring& wstring)
{
    // Create a wstring converter for UTF-8 encoding
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;

    // Convert the wstring to UTF-8 encoded string and return it
    return converter.to_bytes(wstring);
}

std::wstring ToolFunctions::u8stringToWstring(const std::string& u8string)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(u8string);
}