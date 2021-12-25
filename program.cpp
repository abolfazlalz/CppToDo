#include <iostream>
#include <fstream>
#include "classes/CsvFile.cpp"
using namespace std;

int main()
{
  CsvFile file("todo.txt");
  vector<string> dataList;
  dataList.push_back("Hello");
  dataList.push_back("World");
  dataList.push_back("Abolfazl");
  file.AddData(dataList);
  return 0;
}