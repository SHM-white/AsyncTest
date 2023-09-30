#pragma once
#include <string>
//#include <windef.h>
#include <locale>
#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <functional>
#include <regex>
#include <format>
#include <algorithm>
#include <ranges>
#include <fstream>
#include <strsafe.h>
#include <ctime>
#include <exception>
#include <shellapi.h>
#include <shlobj.h>
#include <memory>
#include <codecvt>
//#include "ToWString.h"
#pragma  comment(lib, "shell32.lib")
#pragma warning(disable : 4996)

#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

namespace ToolFunctions {
    std::string wstringToU8string(const std::wstring& wstring);
    std::wstring u8stringToWstring(const std::string& u8string);
}

static auto u8tw = ToolFunctions::u8stringToWstring;
static auto wtu8 = ToolFunctions::wstringToU8string;
