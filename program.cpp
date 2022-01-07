#include <iostream>
#include <fstream>
#include "classes/ToDoController.cpp"
#include "classes/ToDo.cpp"
#include <ctime>

using namespace std;
ToDoController ctrl("todo.csv");

void showOptions();
void showList();
string getLine();
void addToDo();
void changeStatus(bool status);

int main()
{
  showOptions();

  bool program = true;

  while (program)
  {
    int choice;
    cout << "Which one: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      showList();
      break;
    case 2:
      addToDo();
      break;
    case 3:
      changeStatus(true);
      break;
    case 4:
      changeStatus(false);
      break;
    case 0:
      program = false;
      break;
    }
  }

  cout << "Goodbye";

  return 0;
}

void showOptions()
{
  cout << "[1] Show todos list" << endl;
  cout << "[2] Add new todo item" << endl;
  cout << "[3] Mark as done a todo by ID" << endl;
  cout << "[4] Mark as incomplete a todo by ID" << endl;
}

void showList()
{
  for (auto &todo : ctrl.Get())
  {
    cout << (todo[5] == "true" ? "☑" : "☐");
    cout << "  ";
    cout << todo[0] << " " << todo[1] << endl;
  }
}

// https://www.geeksforgeeks.org/getline-string-c/#:~:text=The%20C%2B%2B%20getline()%20is,the%20delimiting%20character%20is%20encountered.
void addToDo()
{
  ToDo todo;
  string text;
  getline(cin, text);
  cout << "Enter todo title: ";
  getline(cin, text);
  todo.setTitle(text);
  cout << "Enter todo description: ";
  getline(cin, text);
  todo.setDescription(text);

  time_t now = time(0);

  todo.setEndTime(now);
  todo.setStartTime(now);
  todo.isDone(false);
  todo.setCategory("todo");
  todo.save();

  cout << "Added successfully" << endl;
}

void changeStatus(bool status)
{
  showList();
  cout << "Enter id to change status: ";
  int id;
  cin >> id;

  auto todo = ToDo::findById(id, "todo");
  todo.isDone(status);
  todo.save();
  cout << "Updated successfully." << endl;
}