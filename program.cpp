#include <iostream>
#include <fstream>
#include "classes/ToDoController.h"
using namespace std;

int main()
{
  time_t now = time(0);
  ToDo file("todo.csv");
  file.AddToDo("Title", "Desc", now, now);
  return 0;
}