#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

struct Student {
    string name, phoneNumber, email, address, bloodGroup, studentID, admittedCourse, admissionType;
    double totalMarks, expectedPackage, feesPaid;
    int rankObtained;
};

struct Course {
    string courseName;
    double kcetFees, managementFees;
};

vector<Student> students;
vector<Course> courses;
const string STUDENTS_FILE = "students.txt", COURSES_FILE = "courses.txt";
const double MANAGEMENT_DISCOUNT = 0.10;

void clearBuffer() { cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
void pressEnter() { cout << "\nPress Enter to continue..."; cin.get(); }

void loadFromFile(const string& filename, vector<string>& lines) {
    ifstream in(filename);
    string line; lines.clear();
    while (getline(in, line)) lines.push_back(line);
}

void saveToFile(const string& filename, const vector<string>& lines) {
    ofstream out(filename);
    for (const auto& line : lines) out << line << '\n';
}

void loadStudents() {
    vector<string> lines; loadFromFile(STUDENTS_FILE, lines);
    students.clear(); Student s; string temp;
    for (const auto& line : lines) {
        stringstream ss(line);
        getline(ss, s.name, ','); getline(ss, s.phoneNumber, ','); getline(ss, s.email, ',');
        getline(ss, s.address, ','); getline(ss, s.bloodGroup, ','); getline(ss, s.studentID, ',');
        getline(ss, s.admittedCourse, ','); getline(ss, s.admissionType, ',');
        getline(ss, temp, ','); s.totalMarks = stod(temp);
        getline(ss, temp, ','); s.rankObtained = stoi(temp);
        getline(ss, temp, ','); s.expectedPackage = stod(temp);
        getline(ss, temp); s.feesPaid = stod(temp);
        students.push_back(s);
    }
}

void loadCourses() {
    vector<string> lines; loadFromFile(COURSES_FILE, lines);
    courses.clear(); Course c; string temp;
    for (const auto& line : lines) {
        stringstream ss(line);
        getline(ss, c.courseName, ','); getline(ss, temp, ','); c.kcetFees = stod(temp);
        getline(ss, temp); c.managementFees = stod(temp);
        courses.push_back(c);
    }
}

void saveStudents() {
    vector<string> lines;
    for (const auto& s : students) {
        lines.push_back(s.name + "," + s.phoneNumber + "," + s.email + "," + s.address + "," +
            s.bloodGroup + "," + s.studentID + "," + s.admittedCourse + "," + s.admissionType + "," +
            to_string(s.totalMarks) + "," + to_string(s.rankObtained) + "," +
            to_string(s.expectedPackage) + "," + to_string(s.feesPaid));
    }
    saveToFile(STUDENTS_FILE, lines);
}

void saveCourses() {
    vector<string> lines;
    for (const auto& c : courses) {
        lines.push_back(c.courseName + "," + to_string(c.kcetFees) + "," + to_string(c.managementFees));
    }
    saveToFile(COURSES_FILE, lines);
}

string generateID() {
    int maxID = 1000;
    for (const auto& s : students) {
        if (s.studentID.substr(0, 3) == "SID")
            maxID = max(maxID, stoi(s.studentID.substr(3)));
    }
    return "SID" + to_string(maxID + 1);
}

void displayCourses() {
    for (const auto& c : courses)
        cout << "Course: " << c.courseName << ", KCET Fees: " << c.kcetFees
             << ", Management Fees: " << c.managementFees << '\n';
}

void addStudent() {
    Student s;
    s.studentID = generateID();
    cout << "Enter name, phone, email, address, blood group:\n";
    getline(cin, s.name); getline(cin, s.phoneNumber); getline(cin, s.email);
    getline(cin, s.address); getline(cin, s.bloodGroup);
    displayCourses();
    cout << "Enter course name: "; getline(cin, s.admittedCourse);
    cout << "Enter admission type (KCET/Management): "; getline(cin, s.admissionType);
    auto it = find_if(courses.begin(), courses.end(), [&](const Course& c) { return c.courseName == s.admittedCourse; });
    if (it == courses.end()) { cout << "Invalid course."; return; }
    s.feesPaid = (s.admissionType == "KCET") ? it->kcetFees : it->managementFees * (1 - MANAGEMENT_DISCOUNT);
    cout << "Enter total marks, rank, expected package:\n";
    while (!(cin >> s.totalMarks) || s.totalMarks < 0 || s.totalMarks > 500) { cin.clear(); clearBuffer(); cout << "Retry marks: "; }
    while (!(cin >> s.rankObtained) || s.rankObtained <= 0) { cin.clear(); clearBuffer(); cout << "Retry rank: "; }
    while (!(cin >> s.expectedPackage) || s.expectedPackage < 0) { cin.clear(); clearBuffer(); cout << "Retry package: "; }
    clearBuffer();
    students.push_back(s); saveStudents(); cout << "Student added: " << s.studentID << '\n';
}

void showAll() {
    if (students.empty()) return void(cout << "No records.\n");
    for (const auto& s : students) {
        cout << s.studentID << ": " << s.name << ", " << s.admittedCourse << ", " << s.admissionType
             << ", Marks: " << s.totalMarks << ", Rank: " << s.rankObtained << "\n";
    }
}

void menu() {
    int ch;
    do {
        cout << "\n1.Add 2.Show All 3.Exit\nChoice: "; cin >> ch; clearBuffer();
        if (ch == 1) addStudent();
        else if (ch == 2) showAll();
        else if (ch != 3) cout << "Invalid.\n";
        pressEnter();
    } while (ch != 3);
}

int main() {
    loadCourses(); loadStudents();
    if (courses.empty()) {
        courses.push_back({"CSE", 150000, 250000});
        courses.push_back({"ECE", 120000, 200000});
        saveCourses();
    }
    menu();
    saveStudents(); return 0;
}
