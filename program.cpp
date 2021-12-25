#include <iostream>
#include <fstream>
#include "classes/ToDoController.cpp"
#include "classes/ToDo.cpp"
using namespace std;

int main()
{
  time_t now = time(0);
  ToDo todo;
  todo.setCategory("todo");
  todo.setTitle("New work");
  todo.setDescription("About this work");
  todo.setStartTime(now);
  todo.setEndTime(now);
  todo.save();
  return 0;
}