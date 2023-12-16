//Rishikesh Chaudhari
//E11 23304

//Implement Heap sort to sort given set of values using max or min heap. Analyze the implement algorithm for space and time complexity

#include <iostream>
using namespace std;
class heap
{
private:
    int size;

public:
    int arr[100];
    heap()
    {
        // arr[0] = -1;
        size = 0;
    }
    void insert(int);
    void deleteFromHeap();
    void print();
    void heapify(int arr[], int n, int i);
    void heapSort(int arr[], int n);
    void minheapify(int arr[], int n, int i);
    void minheapSort(int arr[], int n);
};

void heap ::insert(int val)
{
    size = size + 1;
    int index = size - 1;
    arr[index] = val;
    while (index > 0)
    {
        int parent = index / 2;
        if (arr[parent] < arr[index])
        {
            // swap(arr[parent], arr[index]);
            int temp = arr[parent];
            arr[parent] = arr[index];
            arr[index] = temp;
            index = parent;
        }
        else
        {
            return;
        }
    }
}

void heap ::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heap ::heapify(int arr[], int n, int i)
{
    // 0 based indexing
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heap ::heapSort(int arr[], int n)
{
    int size = n;
    
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void heap ::minheapify(int arr[], int n, int i)
{
    // 0 based indexing
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[largest] > arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] > arr[left])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        minheapify(arr, n, largest);
    }
}

void heap ::minheapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        /* code */
        // Step1->swap
        swap(arr[size], arr[1]);
        size--;
        // Step2
        minheapify(arr, size, 1);
    }
}

int main()
{
    int num1;
    do{
        heap h;
        int num;

        // Insertion of elements
        cout << "Enter number of elements in array" << endl;
        cin >> num;
        int A[num];
        for (int i = 0; i < num; i++)
        {
            cin >> A[i];
            h.insert(A[i]);
        }
        cout<<"Printing heapify array "<<endl;
        h.print();
        cout<<endl;


        h.heapSort(A, num);
        // Printing the array in sorted order
        cout<<"Printing the array in sorted order"<<endl;
        for (int i = 0; i < num; ++i)
        {
            cout << A[i] << " ";
        }
        cout << endl;
        cout<<"Enter 1 to continue"<<endl;
        cin>>num1;
        cout<<endl;
    }
    while (num1 == 1);
   
return 0;   
}
