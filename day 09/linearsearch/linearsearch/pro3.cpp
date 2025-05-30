#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNo;
};

int main() 
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* students = new Student[n];

    cout << "Enter student details (roll number and name):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ":\n";
        cout << "  Roll Number: ";
        cin >> students[i].rollNo;
        cout << "  Name: ";
        cin.ignore(); // Clear newline from input buffer
        getline(cin, students[i].name);
    }

    int keyRollNo;
    cout << "\nEnter the roll number to search: ";
    cin >> keyRollNo;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (students[i].rollNo == keyRollNo)
        {
            cout << "Student found:\n";
            cout << "  Roll Number: " << students[i].rollNo << "\n";
            cout << "  Name: " << students[i].name << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student with roll number " << keyRollNo << " not found in the list." << endl;
    }

    delete[] students;
    return 0;
}
