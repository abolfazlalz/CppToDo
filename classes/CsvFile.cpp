#include "CsvFile.h"

/**
 * Source https://www.techiedelight.com/split-string-cpp-using-delimiter/
 */
vector<string> CsvFile::tokenize(string const &str, const char delim)
{
    vector<string> out;
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        out.push_back(str.substr(start, end - start));
    }
    return out;
}

vector<vector<string>> CsvFile::ReadCsv()
{
    vector<vector<string>> result;
    string content = CsvFile::ReadFile();

    vector<string> lines = tokenize(content, '\n');

    for (auto &line : lines)
    {
        vector<string> dataList = tokenize(line, ',');
        result.push_back(dataList);
    }

    return result;
}

void CsvFile::AddData(vector<string> dataList)
{
    string dataStr = "";
    bool isFirstVal = true;
    for (auto &data : dataList)
    {
        if (isFirstVal)
            isFirstVal = false;
        else
            dataStr += ",";
        dataStr += data;
    }

    AppendLine(dataStr);
}