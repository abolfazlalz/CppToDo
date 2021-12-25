#ifndef ToDo_H
#define ToDo_H

#include "iostream"
#include <ctime>

#include "ToDoController.h"

using namespace std;

class ToDo
{
private:
    string _title;
    string _description;
    time_t _startTime;
    time_t _endTime;

    string _category;

public:
    void setCategory(string category);

    void save();

    void setTitle(string title)
    {
        _title = title;
    }

    void setDescription(string description)
    {
        _description = description;
    }

    void setStartTime(time_t time)
    {
        _startTime = time;
    }

    void setEndTime(time_t time)
    {
        _endTime = time;
    }
};

#endif