#ifndef ToDoController_H
#define ToDoController_H

#include "iostream"
#include <vector>
#include <ctime>
#include <string>

#include "CsvFile.cpp"

using namespace std;

class ToDoController : public CsvFile
{
private:
    string dateToString(time_t date);

public:
    using CsvFile::CsvFile;

    void AddToDo(string title, string description, time_t start, time_t end);
};

#endif