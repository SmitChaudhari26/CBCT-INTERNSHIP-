#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
public:
    int rollNumber;
    string name;
    string course;
    int year;

    void input()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Course: ";
        getline(cin, course);
        cout << "Enter Year: ";
        cin >> year;
    }

    void display()
    {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Year: " << year << endl;
    }
};

void addRecord()
{
    Student student;
    student.input();

    ofstream outFile("students.dat", ios::binary | ios::app);
    outFile.write(reinterpret_cast<char *>(&student), sizeof(Student));
    outFile.close();
    cout << "Record added successfully!" << endl;
    cout << "\n\n\n\n";
}

void displayRecords()
{
    Student student;
    ifstream inFile("students.dat", ios::binary);

    if (!inFile)
    {
        cout << "No records found!" << endl;
        cout << "\n\n\n\n";
        return;
    }

    while (inFile.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        student.display();
        cout << "-----------------------" << endl;
    }
    inFile.close();
}

void searchRecord(int rollNumber)
{
    Student student;
    ifstream inFile("students.dat", ios::binary);
    bool found = false;

    while (inFile.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        if (student.rollNumber == rollNumber)
        {
            student.display();
            found = true;
            cout << "\n\n\n\n";
            break;
        }
    }
    inFile.close();

    if (!found)
    {
        cout << "Record not found!" << endl;
        cout << "\n\n\n\n";
    }
}

void deleteRecord(int rollNumber)
{
    Student student;
    ifstream inFile("students.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);
    bool found = false;

    while (inFile.read(reinterpret_cast<char *>(&student), sizeof(Student)))
    {
        if (student.rollNumber == rollNumber)
        {
            found = true;
            cout << "\n\n\n\n";
        }
        else
        {
            outFile.write(reinterpret_cast<char *>(&student), sizeof(Student));
            cout << "\n\n\n\n";
        }
    }
    inFile.close();
    outFile.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
    {
        cout << "Record deleted successfully!" << endl;
        cout << "\n\n\n\n";
    }
    else
    {
        cout << "Record not found!" << endl;
        cout << "\n\n\n\n";
    }
}

int main()
{
    int choice, rollNumber;

    while (true)
    {
        cout << "**************************************************************************************\n";
        cout << "\n\t\t\t\t\t\tStudent Record Management System\t\t\t\t\t\t\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Search Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Exit\n\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            displayRecords();
            break;
        case 3:
            cout << "Enter Roll Number to search: ";
            cin >> rollNumber;
            searchRecord(rollNumber);
            break;
        case 4:
            cout << "Enter Roll Number to delete: ";
            cin >> rollNumber;
            deleteRecord(rollNumber);
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
