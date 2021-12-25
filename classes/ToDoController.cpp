#include "ToDoController.h"

// https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm

string ToDoController::dateToString(time_t time)
{
    tm *ltm = localtime(&time);
    string result = to_string(1900 + ltm->tm_year) + "/";
    result += to_string(1 + ltm->tm_mon) + "/";
    result += to_string(ltm->tm_mday) + " ";
    result += to_string(ltm->tm_hour) + ":";
    result += to_string(ltm->tm_min);
    return result;
}

// https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c#answer-4654718
bool is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

void ToDoController::AddToDo(string title, string description, time_t start, time_t end)
{
    vector<vector<string>> todos = ReadCsv();

    vector<string> vec;
    int id = 0;
    if (todos.size() > 0)
    {
        vector<string> todo = todos[todos.size() - 1];
        if (todo.size() > 0)
        {
            string lastIdStr = todo[0];
            if (is_number(lastIdStr))
                id = stoi(lastIdStr) + 1;
        }
    }
    vec.push_back(to_string(id));
    vec.push_back(title);
    vec.push_back(description);
    vec.push_back(dateToString(start));
    vec.push_back(dateToString(end));

    AddData(vec);
}