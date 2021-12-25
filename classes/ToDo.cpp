#include "ToDo.h"

void ToDo::setCategory(string category)
{
    _category = category;
}

void ToDo::save()
{
    if (_category == "")
    {
        cout << "Category not defiend" << endl;
        return;
    }
    ToDoController ctrl(_category + ".csv");
    ctrl.AddToDo(_title, _description, _startTime, _endTime);
}