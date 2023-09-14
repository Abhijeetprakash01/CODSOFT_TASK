#include <iostream>
using namespace std;
class list
{
    int capacity;
    int lastindex;
    string *ptr;
    bool *completed;

public:
    list(int);
    void insert(string);
    void viewtask(string);
    void task_update(int);
    void delete_task(int);
};
list::list(int cap)
{
    capacity = cap;
    lastindex = -1;
    ptr = new string[capacity];
    completed = new bool[capacity];
}
void list::insert(string str)
{
    if (lastindex < capacity - 1)
    {
        lastindex++;
        ptr[lastindex] = str;
        bool task_completed = false;
        cout << "enter completion status for the task(0 for incomplete ,1 for complete):";
        cin >> task_completed;
        completed[lastindex] = task_completed;
        cin.ignore();
    }
    else
    {
        cout << "List is full." << endl;
    }
}
void list::viewtask(string str)
{
    if (lastindex == -1)
    {
        cout << "No task to display" << endl;
    }
    else
    {
        for (int i = 0; i <= lastindex; i++)
        {
            cout << " Task " << i + 1 << ptr[i] << "(";
            if (completed[i])
            {
                cout << " completed ";
            }
            else
            {
                cout << " incompleted ";
            }

            cout << ")" << endl;
        }
    }
}
void list::task_update(int ptr)
{
    if (ptr >= 1 && ptr <= lastindex + 1)
    {
        completed[ptr - 1] = true;
        cout << " Task " << ptr << " marked as completed " << endl;
    }
    else
    {
        cout << "task number is not valid" << endl;
    }

    char choice;
    cout << "Do you want to update another task? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        cout << endl;
        int newTask;
        cout << "Enter the task no. you want to update: ";
        cin >> newTask;
        task_update(newTask);
    }

    char choice1;
    cout << "Do you want to add a new task? (y/n): ";
    cin >> choice1;

    if (choice1 == 'y' || choice1 == 'Y')
    {
        string newTask;
        cin.ignore(); // Clear newline from previous input
        cout << "Enter the new task: ";
        getline(cin, newTask);
        insert(newTask); // Call the insert function to add the new task
    }
}

void list::delete_task(int task_index)
{
    if (task_index >= 1 && task_index <= lastindex + 1)
    {
        // Shift tasks to remove the task at the specified index
        for (int i = task_index - 1; i < lastindex; i++)
        {
            ptr[i] = ptr[i + 1];
            completed[i] = completed[i + 1];
        }

        // Decrement lastindex to reflect the removed task
        lastindex--;

        cout << "Task " << task_index << " deleted successfully." << endl;
    }
    else
    {
        cout << "Invalid task index. No task deleted." << endl;
    }
}

int main()
{
    list li(5);
    string task;

    while (true)
    {
        cout << "Enter the task you want to add (or type 'exit' to stop):" << endl;
        getline(cin, task);

        if (task == "exit")
        {
            break; // Exit the loop if the user types 'exit'
        }

        li.insert(task);
    }
    li.viewtask(task);
    li.task_update(1);
    li.viewtask(task);

    char choice3;
    cout << "Do you want to delete any task? (y/n): ";
    cin >> choice3;

    if (choice3 == 'y' || choice3 == 'Y')
    {

        cout << endl; // Add a newline
        int newTask;
        cout << "Do you want to delete a task? (y/n): ";
        cin >> choice3;
        li.delete_task(newTask);
    }
    li.viewtask(task);

    return 0;
}
