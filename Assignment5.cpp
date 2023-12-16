//Rishikesh Chaudhari
//E11 23304

#include <iostream>
#include "stack.h"

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class MyBST
{

private:
    node *root;

public:
    MyBST()
    {
        root = NULL;
    }
    void insert(int x);
    node *makenode(int x);
    void inorder(node *root);
    void preorder(node *root);
    void postorder(node *root);
    node *getRoot();
    void search(int key);
    int height(node *root);
    void mirror(node *root);
    void copyTree(node *root, node *&root1);
    void printNode(node *root);
    void printLeafNode(node *root);
    node *deleteNode(node *root, int val);
    node *minVal(node *root);
    void levelOrder(node *root);
};

void MyBST ::levelOrder(node *root)
{
    Stack<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.isEmpty())
    {
        node *temp = q.peep();
        // cout<<"temp = "<<temp->data<<endl;
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.isEmpty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

node *MyBST ::minVal(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node *MyBST ::deleteNode(node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {

        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // i)left child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // ii)right child
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }

    else if (root->data > val)
    {
        root->left = deleteNode(root->left, val);
    }

    else
    {
        root->right = deleteNode(root->right, val);
    }

    return root;
}

void MyBST ::printLeafNode(node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
    }

    if (root->left == NULL && root->right == NULL)
    {
        cout << "Leaf Node = " << root->data << endl;
    }

    else
    {
        printLeafNode(root->left);
        printLeafNode(root->right);
    }
}

void MyBST ::printNode(node *root)
{

    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    else
    {
        cout << "Parent = " << root->data << endl;
        if (root->left != NULL)
        {
            cout << "Left node = " << root->left->data << endl;
        }
        if (root->right != NULL)
        {
            cout << "Right Node = " << root->right->data << endl;
        }

        printNode(root->left);
        printNode(root->right);
    }
}

void MyBST ::copyTree(node *root, node *&root1)
{

    if (root == NULL)
    {
        root1 = NULL;
    }

    else
    {
        root1 = new node();
        root1->data = root->data;

        copyTree(root->left, root1->left);
        copyTree(root->right, root1->right);
    }
}

void MyBST ::mirror(node *root)
{
    if (root != NULL)
    {
        node *temp = root->right;
        root->right = root->left;
        root->left = temp;

        mirror(root->left);
        mirror(root->right);
    }
}

void MyBST ::insert(int x)
{
    if (root == NULL)
    {
        root = makenode(x);
        return;
    }

    node *p = root;
    node *q = root;
    while (q != NULL && x != p->data)
    {
        p = q;
        if (x < p->data)
        {
            q = p->left;
        }

        else
        {
            q = p->right;
        }
    }

    if (x == p->data)
    {
        cout << "Please enter the valid data" << endl;
        cout << "Duplication is not allowed" << endl;
        return;
    }

    if (x < p->data)
    {
        cout << "Entering to the left of " << p->data << endl;
        p->left = makenode(x);
    }

    else
    {
        cout << "Entering data to the right of " << p->data << endl;
        p->right = makenode(x);
    }
}

node *MyBST ::makenode(int x)
{
    node *p = new node;
    p->data = x;
    p->right = NULL;
    p->left = NULL;
    return p;
}

void MyBST ::inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void MyBST ::postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void MyBST ::preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

node *MyBST ::getRoot()
{
    return root;
}

void MyBST ::search(int key)
{

    node *p = root;
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
    }

    else
    {
        while (p)
        {
            if (key == p->data)
            {
                cout << key << " is present in tree" << endl;
                return;
            }

            else if (key < p->data)
            {
                p = p->left;
            }

            else
            {
                p = p->right;
            }
        }
    }

    cout << "Element is not present" << endl;
}

int MyBST ::height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    else
    {
        node *leftAns = root->left;
        node *rightAns = root->right;
        return 1 + max(height(leftAns), height(rightAns));
    }
}

int main()
{

    MyBST T;
    int y = 0;
    int ch;
    int n;
    cout << "Enter the number of nodes you want initially" << endl;
    cin >> n;
    int z;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the data to enter" << endl;
        cin >> z;
        T.insert(z);
    }

    do
    {

        cout << "Enter 1 for insertion" << endl;
        cout << "Enter 2 for inorder" << endl;
        cout << "Enter 3 for postorder" << endl;
        cout << "Enter 4 for preorder" << endl;
        cout << "Enter 5 to data in tree" << endl;
        cout << "Enter 6 to get height of tree" << endl;
        cout << "Enter 7 to get mirror of tree and to traverse it" << endl;
        cout << "Enter 8 to create the copy of the tree traverse it" << endl;
        cout << "Enter 9 to display the parent nodes as well as their child nodes" << endl;
        cout << "Enter 10 to display the leaf nodes" << endl;
        cout << "Enter 11 to delete a node" << endl;
        cout << "Enter 12 to level order traversal" << endl;
        cout << "ENTER CHOICE" << endl;
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
            T.inorder(T.getRoot());
            cout << endl;
        }

        else if (ch == 3)
        {
            T.postorder(T.getRoot());
            cout << endl;
        }

        else if (ch == 4)
        {
            T.preorder(T.getRoot());
            cout << endl;
        }

        else if (ch == 5)
        {
            int key;
            cout << "Enter the key to be searched" << endl;
            cin >> key;
            T.search(key);
            cout << endl;
        }

        else if (ch == 6)
        {
            int height = T.height(T.getRoot());
            cout << "Height is " << height << endl;
            cout << endl;
        }
        else if (ch == 7)
        {
            T.mirror(T.getRoot());
            T.inorder(T.getRoot());
            cout << endl;
        }

        else if (ch == 8)
        {
            node *root1;
            T.copyTree(T.getRoot(), root1);
            cout << "Traversing original tree" << endl;
            T.inorder(T.getRoot());
            cout << endl;
            cout << "Traversing copied tree" << endl;
            T.inorder(root1);
            cout << endl;
        }

        else if (ch == 9)
        {
            T.printNode(T.getRoot());
            cout << endl;
        }

        else if (ch == 10)
        {
            T.printLeafNode(T.getRoot());
            cout << endl;
        }

        else if (ch == 11)
        {
            int val;
            cout << "Enter the value to delete" << endl;
            cin >> val;
            node *temp = T.deleteNode(T.getRoot(), val);
            cout << endl;
        }

        else if (ch == 12)
        {
            T.levelOrder(T.getRoot());
            cout << endl;
        }

        else
        {
            cout << "Entet the valid choice " << endl;
        }
        cout << "If you want to continue enter 1" << endl;
        cin >> y;
    } while (y == 1);
}