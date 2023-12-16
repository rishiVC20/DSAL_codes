//Rishikesh Chaudhari
//E11 23304

//Implement Program for sequential access file

#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
struct Student
{
    int roll_no;
    char name[15];
    int div;
    char addr[200];
};
class Mystdb
{
public:
    void add_db()
    {
        int n;
        ofstream file;
        cout << "How many Students to add to database : " << endl;
        cin >> n;
        file.open("std.txt", ios::out);
        for (int i = 0; i < n; i++)
        {
            Student stdrc;
            cout << "Enter Roll Number of Student : " << endl;
            cin >> stdrc.roll_no;
            cout << "Enter Name : " << endl;
            cin >> stdrc.name;
            cout << "Enter Division" << endl;
            cin >> stdrc.div;
            cout << "Enter Address" << endl;
            cin >> stdrc.addr;
            file.write((char *)&stdrc, sizeof(stdrc));
        }
        file.close();
    }

public:
    void add_rc()
    {
        ofstream file;
        file.open("std.txt", ios::app);
        Student stdrc;
        cout << "Enter Roll Number of Student : " << endl;
        cin >> stdrc.roll_no;
        cout << "Enter Name : " << endl;
        cin >> stdrc.name;
        cout << "Enter Division" << endl;
        cin >> stdrc.div;
        cout << "Enter Address" << endl;
        cin >> stdrc.addr;
        file.write((char *)&stdrc, sizeof(stdrc));
    }

public:
    void display_all()
    {
        ifstream file;
        Student stdrc;
        file.open("std.txt", ios::in);
        while (file.read((char *)&stdrc, sizeof(stdrc)))
        {
            cout << "Student Roll No. : " << stdrc.roll_no << endl;
            cout << "Student Name : " << stdrc.name << endl;
            cout << "Student Division : " << stdrc.div << endl;
            cout << "Student Address : " << stdrc.addr << endl;
        }
        file.close();
    }

public:
    void search(int rn)
    {
        ifstream file;
        Student stdrc;
        file.open("std.txt", ios::in);
        while (file.read((char *)&stdrc, sizeof(stdrc)))
        {
            if (stdrc.roll_no == rn)
            {
                cout << "Found " << rn << endl;
                file.close();
                return;
            }
        }
        cout << "Not Found " << endl;
        file.close();
    }

public:
    void del_rc(int key)
    {
        ifstream file;
        file.open("std.txt", ios::in);
        Student stdrc;
        ofstream temp;
        bool found = 0;
        temp.open("temp.txt", ios::out);
        while (file.read((char *)&stdrc, sizeof(stdrc)))
        {
            if (stdrc.roll_no != key)
            {
                temp.write((char *)&stdrc, sizeof(stdrc));
            }
            else
            {
                found = 1;
            }
        }
        file.close();
        temp.close();
        remove("std.txt");
        rename("temp.txt", "std.txt");
        if (found)
        {
            cout << "Deleted : " << key << endl;
        }
        else
        {
            cout << "Element Not Found to Delete" << endl;
        }
    }

public:
    void modify_rc(int key)
    {
        ifstream file;
        file.open("std.txt", ios::in);
        Student stdrc;
        ofstream temp;
        bool found = 0;
        temp.open("temp.txt", ios::out);
        while (file.read((char *)&stdrc, sizeof(stdrc)))
        {
            if (stdrc.roll_no == key)
            {
                cout << "Enter data to Modify " << endl;
                cout << "Enter Roll Number of Student : " << endl;
                cin >> stdrc.roll_no;
                cout << "Enter Name : " << endl;
                cin >> stdrc.name;
                cout << "Enter Division" << endl;
                cin >> stdrc.div;
                cout << "Enter Address" << endl;
                cin >> stdrc.addr;
                found = 1;
            }
            temp.write((char *)&stdrc, sizeof(stdrc));
        }
        file.close();
        temp.close();
        remove("std.txt");
        rename("temp.txt", "std.txt");
        if (found)
        {
            cout << "Modified : " << key << endl;
        }
        else
        {
            cout << "Element Not Found to Modify" << endl;
        }
    }

public:
    void clear_db()
    {
        ofstream file;
        file.open("std.txt", ios::trunc);
        file.close();
    }
};
int main()
{
    Mystdb s;
    int choice, rollNo;

    do
    {
        cout << "\n*** Student Database Management System ***\n";
        cout << "1. Add Students to Database\n";
        cout << "2. Add a Single Student Record\n";
        cout << "3. Display All Students\n";
        cout << "4. Search for a Student\n";
        cout << "5. Delete a Student Record\n";
        cout << "6. Modify a Student Record\n";
        cout << "7. Clear Database\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.add_db();
            break;

        case 2:
            s.add_rc();
            break;

        case 3:
            s.display_all();
            break;

        case 4:
            cout << "Enter Roll Number to search: ";
            cin >> rollNo;
            s.search(rollNo);
            break;

        case 5:
            cout << "Enter Roll Number to delete: ";
            cin >> rollNo;
            s.del_rc(rollNo);
            break;

        case 6:
            cout << "Enter Roll Number to modify: ";
            cin >> rollNo;
            s.modify_rc(rollNo);
            break;

        case 7:
            s.clear_db();
            cout << "Database cleared.\n";
            break;

        case 8:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

    } while (choice != 8);

    return 0;
}
