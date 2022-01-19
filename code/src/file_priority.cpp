#include "file_priority.h"

const int PRIORITY_LEN = 10;

string GetNextStr(string::iterator &it, string::iterator &end)
{
    string retStr = "";
    while (*it == ' ') {
        it++;
    }
    while (*it != ' ' && it != end) {
        retStr += *it++;
    }
    return retStr;
}

FilePriority::FilePriority(const char *oldFileName, const char *newFileName) :
    oldFileName(string(oldFileName)), newFileName(string(newFileName)) {}

FilePriority::~FilePriority()
{
    if (oldFile.is_open()) {
        oldFile.close();
    }
    if (newFile.is_open()) {
        newFile.close();
    }
}

void FilePriority::Run()
{
    ReadOldFile();
    WriteNewFile();
}

void FilePriority::ReadOldFile()
{
    oldFile.open(oldFileName.c_str(), ios::in);

    string tmpStr;
    string tmpFolder;
    while(getline(oldFile, tmpStr)) {
        if (regex_match(tmpStr, folderPattern)) {
            tmpStr.pop_back();
            tmpFolder = tmpStr;
            maxSizeInfoSt.dirSize = max(maxSizeInfoSt.dirSize, tmpFolder.size());
        }
        if (regex_match(tmpStr, filePattern)) {
            FileInfoSt fileInfo;
            GetFileStrInfo(tmpStr, fileInfo);
            dirFileMap[tmpFolder].emplace_back(fileInfo);
            RefreshSizeInfo(fileInfo);
        }
    }

    oldFile.close();
}

void FilePriority::GetFileStrInfo(string &fileStr, FileInfoSt &fileInfo)
{
    string::iterator it = fileStr.begin();
    string::iterator end = fileStr.end();

    fileInfo.priority   = GetNextStr(it, end);
    fileInfo.fileNum    = GetNextStr(it, end);
    fileInfo.owner      = GetNextStr(it, end);
    fileInfo.group      = GetNextStr(it, end);
    fileInfo.fileSize   = GetNextStr(it, end);
    fileInfo.month      = GetNextStr(it, end);
    fileInfo.day        = GetNextStr(it, end);
    fileInfo.time       = GetNextStr(it, end);
    fileInfo.fileName   = GetNextStr(it, end);
}

void FilePriority::RefreshSizeInfo(const FileInfoSt &fileInfo)
{
    maxSizeInfoSt.prioritySize  = max(maxSizeInfoSt.prioritySize,   fileInfo.priority.size());
    maxSizeInfoSt.fileNumSize   = max(maxSizeInfoSt.fileNumSize,    fileInfo.fileNum.size());
    maxSizeInfoSt.ownerSize     = max(maxSizeInfoSt.ownerSize,      fileInfo.owner.size());
    maxSizeInfoSt.groupSize     = max(maxSizeInfoSt.groupSize,      fileInfo.group.size());
    maxSizeInfoSt.fileSizeSize  = max(maxSizeInfoSt.fileSizeSize,   fileInfo.fileSize.size());
    maxSizeInfoSt.monthSize     = max(maxSizeInfoSt.monthSize,      fileInfo.month.size());
    maxSizeInfoSt.daySize       = max(maxSizeInfoSt.daySize,        fileInfo.day.size());
    maxSizeInfoSt.timeSize      = max(maxSizeInfoSt.timeSize,       fileInfo.time.size());
    maxSizeInfoSt.fileNameSize  = max(maxSizeInfoSt.fileNameSize,   fileInfo.fileName.size());
}

void FilePriority::WriteNewFile()
{
    newFile.open(newFileName,  ios::trunc|ios::out);

    for (const auto&[dirStr, fileInfoList] : dirFileMap) {
        for (const auto &fileInfo : fileInfoList) {
            WriteLine(dirStr, fileInfo);
        }
    }

    newFile.close();
}

void FilePriority::WriteLine(const string &dirStr, const FileInfoSt &fileInfoSt)
{
    newFile << GetStringWithSpace(fileInfoSt.priority,  maxSizeInfoSt.prioritySize);
    newFile << GetStringWithSpace(fileInfoSt.fileNum,   maxSizeInfoSt.fileNumSize);
    newFile << GetStringWithSpace(fileInfoSt.owner,     maxSizeInfoSt.ownerSize);
    newFile << GetStringWithSpace(fileInfoSt.group,     maxSizeInfoSt.groupSize);
    newFile << GetStringWithSpace(fileInfoSt.fileSize,  maxSizeInfoSt.fileSizeSize);
    newFile << GetStringWithSpace(fileInfoSt.month,     maxSizeInfoSt.monthSize);
    newFile << GetStringWithSpace(fileInfoSt.day,       maxSizeInfoSt.daySize);
    newFile << GetStringWithSpace(fileInfoSt.time,      maxSizeInfoSt.timeSize);
    newFile << dirStr + "/" + fileInfoSt.fileName << endl;
}

string FilePriority::GetStringWithSpace(const string &input, const size_t maxLen)
{
    return input + string(maxLen - input.size() + 1, ' ');
}
