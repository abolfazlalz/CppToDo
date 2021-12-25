#include "FileUtils.h"

FileUtils::FileUtils(string fileName)
{
    SetFileName(fileName);
}

string FileUtils::ReadFile()
{
    string line;
    string lines;
    ifstream myFile(_fileName);
    bool firstLine = true;
    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            if (firstLine)
                firstLine = false;
            else
                lines += "\n";
            lines += line;
        }
        myFile.close();
    }
    return lines;
}

void FileUtils::WriteFile(string line)
{
    ofstream myFile;
    myFile.open(_fileName);
    myFile << line;
    myFile.close();
}

void FileUtils::AppendLine(string line)
{
    string content = ReadFile();
    if (content != "")
        content += "\n";
    WriteFile(content + line);
}

void FileUtils::SetFileName(string fileName)
{
    this->_fileName = fileName;
}