//Rishikesh Chaudhari
//E11 23304

// Write a program to accept student database and perform different searching operations: Linear and binary and sorting algorithms: Bubble, Insertion and quick.

#include <iostream>
using namespace std;

struct Student
{
    int rno;
    string name;
    float sgpa;
};

class SE11
{
private:
    struct Student S[25];

public:
    void accept();
    void bubbleSort();
    void display();
    int n = 6;
    void linearSearch();
    int partition(int, int);
    void binarySearch();
    void insertionSort();
    void quickSort(int, int);
};

void SE11 ::accept()
{
    /* Accepts student database
     cout << "Enter number of students " << endl;
     cin >> n;

     for (int i = 0; i < n; i++)
     {
         cout << "Enter name of student ";
         cin >> S[i].name;

         cout << "Enter Roll number of student ";
         cin >> S[i].rno;

         cout << "Enter SGPA of student ";
         cin >> S[i].sgpa;
     }
     cout << endl;*/
    S[0] = {28, "johnson", 4.84};
    S[1] = {85, "marnus", 6.64};
    S[2] = {58, "shane", 7.52};
    S[3] = {68, "peter", 8.96};
    S[4] = {43, "smith", 5.89};
    S[5] = {59, "tim", 7.54};
}

void SE11 ::bubbleSort()
{
    // Arranging students according to their roll numbers in ascending order
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (S[j].rno > S[j + 1].rno)
            {
                swap(S[j].rno, S[j + 1].rno);
            }
        }
    }
    cout << "Students sorted according to roll numbers " << endl;
    cout << "R No. \t Name \t SGPA" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << S[i].rno << "\t" << S[i].name << "\t" << S[i].sgpa << endl;
    }
    cout << endl;
}

void SE11 ::display()
{
    // Displays student database
    for (int i = 0; i < 6; i++)
    {
        cout << "Name of student " << i + 1 << " is " << S[i].name << " " << endl;
        cout << "Roll number of student " << i + 1 << " is " << S[i].rno << " " << endl;
        cout << "SGPA of student " << i + 1 << " is " << S[i].sgpa << " " << endl;
    }
    cout << endl;
}

void SE11 ::linearSearch()
{
    // Searching student according to SGPA
    float tsgpa;
    cout << "Enter the SGPA of student to be search ";
    cin >> tsgpa;
    for (int i = 0; i < 6; i++)
    {
        if (S[i].sgpa == tsgpa)
        {
            cout << "person with the same sgpa is " << S[i].name << " with roll number" << S[i].rno << endl;
            break;
        }
    }

    cout << "No such person exists " << endl;
}

void SE11 ::insertionSort()
{
    // Arranging students alphabetically
    for (int i = 1; i < n; i++)
    {
        string temp = S[i].name;
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (S[j].name > temp)
            {
                S[j + 1].name = S[j].name;
            }
            else
            {
                break;
            }
        }
        S[j + 1].name = temp;
    }
    cout << "Students sorted alphabetically " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << S[i].name << " ";
    }
    cout << endl;
}

void SE11 ::binarySearch()
{
    // Searching a particular student according to name
    cout << "Enter name of student to be search ";
    string nameOfStudent;
    cin >> nameOfStudent;
    int low = 0;
    int high = 5;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (S[mid].name == nameOfStudent)
        {
            cout << "Student name is " << S[mid].name << " with roll number " << S[mid].rno << " has " << S[mid].sgpa << " SGPA " << endl;
            break;
        }
        else if (nameOfStudent > S[mid].name)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

int SE11 ::partition(int low, int high)
{

    int j = high + 1;
    float pivot = S[low].sgpa;
    int i = low;

    while (i < j)
    {
        do
        {
            i++;
        } while (S[i].sgpa > pivot);
        do
        {
            j--;
        } while (S[j].sgpa < pivot);
        if (i < j)
        {
            struct Student t = S[i];
            S[i] = S[j];
            S[j] = t;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        cout << S[i].sgpa << " ";
    }
    cout << endl;
    struct Student t = S[low];
    S[low] = S[j];
    S[j] = t;

    return j;
}

void SE11 ::quickSort(int low, int high)
{
    // Arranging toppers
    //  if (low >= high)
    //  {
    //      return;
    //  }
    if (low < high)
    {
        int p = partition(low, high);

        // Partitioning left part
        quickSort(low, p - 1);

        // Partitioning right part
        quickSort(p + 1, high);
    }

    /* cout<<"Toppers of class are "<<endl;
     cout<<"SGPA \t Name \t Roll number "<<endl;
     for (int i = 0 ; i <n ; i++)
     {
         cout << S[i].sgpa << "\t"<<S[i].name<<"\t"<<S[i].rno<<endl;
     }
     cout << endl;*/
}

int main()
{
    SE11 candidate;
    int num1, num2, oprn;

    num1 = candidate.n;
    candidate.accept();
    candidate.display();
    do
    {
        cout << "operations:" << endl;
        cout << "1.Arrange list of students according to roll numbers in ascending order (Using Bubble Sort)." << endl;
        cout << "2.Arrange list of students alphabeticall (Using Insertion sort)" << endl;
        cout << "3.Arrange list of students to find out first ten toppers from a class (Using Quick sort)" << endl;
        cout << "4.Search students according to SGPA. If more than one student having same SGPA,then print list of all students having same SGPA (Using Linear Search) " << endl;
        cout << "5. Search a particular student according to name using binary search without recursion (Using Binary Search)" << endl;

        cout << "Enter operation number to perform ";

        cin >> oprn;
        cout << endl;

        switch (oprn)
        {
        case 1:
            candidate.bubbleSort();
            break;

        case 2:
            candidate.insertionSort();
            break;

        case 3:
            candidate.quickSort(0, num1);
            break;

        case 4:
            candidate.linearSearch();
            break;

        case 5:
            candidate.binarySearch();
            break;

        default:
            "wrong operation enetered...";
        }
        cout << "Press 1 to continue ";
        cin >> num2;
    } while (num2 == 1);
}
