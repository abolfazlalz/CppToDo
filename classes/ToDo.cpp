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
    if (this->_id == -1)
    {
        ctrl.AddToDo(_title, _description, _startTime, _endTime, _isDone);
    }
    else
    {
        ctrl.UpdateToDo(this->_id, _title, _description, _isDone);
    }
}

void ToDo::print()
{
    cout << this->_id << ". " << this->_title << ": " << this->_description << endl;
}

ToDo ToDo::findById(int id, string category)
{
    if (category == "")
    {
        cout << "Category not defiend" << endl;
        return ToDo();
    }
    ToDoController ctrl(category + ".csv");
    auto data = ctrl.FindByIdToDo(id);
    ToDo todo;

    todo.setId(stoi(data[0]));
    todo.setTitle(data[1]);
    todo.setDescription(data[2]);
    todo.isDone(data[5] == "true" ? true : false);
    return todo;
}