#ifndef FileUtils_H
#define FileUtils_H

#include "iostream"
#include <string>
#include <fstream>

using namespace std;

class FileUtils
{
private:
    string _fileName;

public:
    FileUtils(string fileName);

    void AppendLine(string line);

    void WriteFile(string contents);

    string ReadFile();

    void SetFileName(string fileName);
};

#endif