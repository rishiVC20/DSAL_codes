//Rishikesh Chaudhari
//E11 23304

//Implement In-order Threaded Binary Tree. Traverse the implemented tree in Pre- order too.

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    bool lt;
    bool rt;
};

class TBT
{
    Node *root;
    Node *head;

public:
    TBT()
    {
        head = getNode(-999);
        root = NULL;
    }

    Node *getNode(int data);
    void insert(int x);

    void inorder();

    void preorder();
};

void TBT ::preorder()
{
    Node *curr = head->left;

    if (curr->left == head)
    {
        cout << "Tree is empty" << endl;
        return;
    } 

    while (curr != head)
    {

        cout << curr->data << " ";
        // go to the leftmost part and print the parents
        if (curr->lt == 0)
        {
            curr = curr->left;
        }

        else
        {
            while (curr->rt == 1)
            {
                curr = curr->right;
            }

            curr = curr->right;
        }
    }
}

void TBT ::inorder()
{
    Node *curr = head->left;
    if (curr->left == head)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    while (curr->lt == 0)
    {
        curr = curr->left; // go to the leftmost of the tree
    }

    while (curr != head)
    {
        cout << curr->data << " ";
        if (curr->rt == 1)
        {
            curr = curr->right;
        }

        else
        {
            curr = curr->right;
            while (curr->lt == 0)
            {
                curr = curr->left;
            }
        }
    } // end of inorder
}

void TBT ::insert(int x)
{
    if (head == NULL)
    {
        cout << "Create head first" << endl;
        head = getNode(-999);
    }

    if (root == NULL)
    {
        root = getNode(x);
        head->left = root;
        head->lt = 0;
        root->left = head;
        root->right = head;
    }

    else
    {
        Node *P = root;
        while (true)
        {
            cout << "left = 1 and right = 2 of " << P->data << endl;
            int ch;
            cin >> ch;
            if (ch == 1)
            {
                if (P->lt == 1)
                {
                    Node *Q = getNode(x);
                    Q->left = P->left;
                    Q->right = P;
                    P->left = Q;
                    P->lt = 0;
                    break;
                }
                else
                {
                    P = P->left;
                }
            }

            if (ch == 2)
            {
                if (P->rt == 1)
                {
                    Node *Q = getNode(x);
                    Q->right = P->right;
                    Q->left = P;
                    P->right = Q;
                    P->rt = 0;
                    break;
                }

                else
                {
                    P = P->right;
                }
            }
        }
    }
}

Node *TBT ::getNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->rt = temp->lt = 1;
    temp->left = temp;
    temp->right = temp;
    return temp;
}

int main()
{
    TBT T;
    int y;
    do
    {
        int ch;
        cout << "Enter 1 to insert" << endl;
        cout << "Enter 2 for inorder" << endl;
        cout << "Enter 3 for preorder" << endl;
        cin >> ch;
        if (ch == 1)
        {
            int x;
            cout << "Enter the data to enter" << endl;
            cin >> x;
            T.insert(x);
        }
        else if (ch == 2)
        {
            T.inorder();
            cout << endl;
        }

        else if (ch == 3)
        {
            T.preorder();
            cout << endl;
        }

        cout << "Enter 1 to continue" << endl;
        cin >> y;
    } while (y == 1);
    return 0;
}