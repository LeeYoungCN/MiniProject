#include "string_public_func.h"
#include "public_def.h"
using namespace std;

string GetNextStr(string::const_iterator &it, string::const_iterator &end, const char splitChar)
{
    string retStr = "";
    while (*it == splitChar && *it != '\0' && it != end) {
        it++;
    }
    while (*it != splitChar && *it != '\0' && it != end) {
        retStr += *it++;
    }
    return retStr;
}

namespace UTF8 {
const UINT32 CHINESE_WORD_SPACE_NUM = 2;
const UINT32 CHINESE_WORD_CHAR_NUM  = 3;
const UINT8  UTF8_MULTI_CHAR_FLAG = 0x80;

UINT64 GetStrSpaceSize(const std::string str)
{
    UINT64 size = 0; 
    for(UINT32 i = 0; str[i] != '\0';) {
        if (str[i] & UTF8_MULTI_CHAR_FLAG) {
            size += CHINESE_WORD_SPACE_NUM;
            i    += CHINESE_WORD_CHAR_NUM;
        } else {
            size++;
            i++;
        }
    }
    return size;
}

string GetStrWithSpace(const std::string str, const UINT32 maxLen, const UINT32 suffixSpceNum)
{
    UINT64 tmpNum = GetStrSpaceSize(str);
    UINT64 spaceNum = suffixSpceNum + (maxLen > tmpNum ? maxLen - tmpNum : 0);

    return str + string(spaceNum, ' ');
}
}