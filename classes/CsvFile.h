#ifndef CsvFile_H
#define CsvFile_H

#include "iostream"
#include <string>
#include "map"
#include <vector>

#include "FileUtils.cpp"

using namespace std;

class CsvFile : public FileUtils
{
private:
    string _fileName;
    std::vector<std::string> tokenize(std::string const &str, const char delim);

public:
    using FileUtils::FileUtils;
    vector<vector<string>> ReadCsv();
    void AddData(vector<string> dataList);
};

#endif