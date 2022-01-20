#ifndef STRING_PUBLIC_FUNC_H
#define STRING_PUBLIC_FUNC_H
#include <iostream>
#include "public_def.h"

std::string GetNextStr(std::string::const_iterator &it, std::string::const_iterator &end, const char splitChar);
namespace UTF8{
UINT64 GetStrSpaceSize(const std::string str);
std::string GetStrWithSpace(const std::string str, const UINT32 maxLen, const UINT32 suffixSpceNum);
}
#endif // STRING_PUBLIC_FUNC_H