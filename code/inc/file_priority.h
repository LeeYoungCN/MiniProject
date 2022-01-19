#ifndef FILE_PRIORITY_H
#define FILE_PRIORITY_H
#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <vector>

using namespace std;

struct FileInfoSt {
    string priority;
    string fileNum;
    string owner;
    string group;
    string fileSize;
    string month;
    string day;
    string time;
    string fileName;
};

struct MaxSizeInfoSt {
    size_t dirSize;
    size_t prioritySize;
    size_t fileNumSize;
    size_t ownerSize;
    size_t groupSize;
    size_t fileSizeSize;
    size_t monthSize;
    size_t daySize;
    size_t timeSize;
    size_t fileNameSize;
};

class FilePriority {
public:
    FilePriority(const char *oldFileName, const char *newFileName);
    ~FilePriority();
    void Run();
private:
    void ReadOldFile();
    void GetFileStrInfo(string &fileStr, FileInfoSt &fileInfo);
    void RefreshSizeInfo(const FileInfoSt &fileInfo);

    void WriteNewFile();
    void WriteLine(const string &dirStr, const FileInfoSt &fileInfoSt);
    string GetStringWithSpace(const string &input, const size_t maxLen);
    // 文件名
    string oldFileName;
    string newFileName;
    // 文件流
    ifstream oldFile;
    ofstream newFile;
    // 正则表达式模式
    regex folderPattern{".*:$"};                   // 路径模式
    regex filePattern{"^.{1}([-r][-w][-x]){3}.*"}; // 文件模式
    //
    map<string, vector<FileInfoSt>> dirFileMap;
    MaxSizeInfoSt maxSizeInfoSt = {0};
};

#endif // FILE_PRIORITY_H
