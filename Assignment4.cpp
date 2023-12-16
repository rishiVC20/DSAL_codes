//Rishikesh Chaudhari
//E11 23304

//Construct an expression tree for postfix expression and perform recursive and non-recursive Inorder,Preorder and Postorder traversals.

#include <iostream>
#include "stack.h";
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
};

class ExpressionTree
{
private:
    struct node *p;
    string exp;
    int n;

public:
    void accept();
    void inorrec(node *ptr);
    void prerrec(node *ptr);
    void postrrec(node *ptr);
    void preorder(node *root);
    void postorder(node *root);
    void inorder(node *root);
    void maketree();
    node *getroot();
};

void ExpressionTree ::accept()
{
    cout << "Enter postfix expression : ";
    cin >> exp;
    n = exp.length();
}

void ExpressionTree ::inorrec(node *root)
{
    if (root != NULL)
    {
        inorrec(root->left);
        cout << root->data;
        inorrec(root->right);
    }
}

void ExpressionTree ::prerrec(node *root)
{
    if (root != NULL)
    {
        cout << root->data;
        prerrec(root->left);
        prerrec(root->right);
    }
}

void ExpressionTree ::postrrec(node *root)
{
    if (root != NULL)
    {
        postrrec(root->left);
        postrrec(root->right);
        cout << root->data;
    }
}

void ExpressionTree ::inorder(node *root)
{
    Stack<node *> s;
    s.push(NULL);
    node *current = root;
    while (current != NULL || s.isEmpty() != true)
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }
        cout << s.peep()->data;
        current = s.peep();
        s.pop();
        current = current->right;
    }
}
void ExpressionTree ::preorder(node *root)
{
    Stack<node *> s;
    s.push(NULL);
    node *current = root;
    while (current != NULL || s.isEmpty() != true)
    {
        while (current != NULL)
        {
            cout << s.peep()->data;
            s.push(current);
            current = current->left;
        }
        current = s.peep();
        s.pop();
        current = current->right;
    }
}

void ExpressionTree ::postorder(node *root)
{
    Stack<node *> s1, s2;
    s1.push(root);
    while (s1.isEmpty() != true)
    {
        node *temp = s1.peep();
        s2.push(temp);
        s1.pop();
        if (temp->left)
            s1.push(temp->left);
        if (temp->right)
            s1.push(temp->right);
    }
    while (s2.isEmpty() != true)
    {
        cout << s2.peep()->data;
        s2.pop();
    }
    cout << endl;
}

void ExpressionTree::maketree()
{
    Stack<node *> s;
    for (int i = 0; i < n; i++)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
        {
            node *temp = new node;
            temp->data = exp[i];
            temp->left = NULL;
            temp->right = NULL;
            s.push(temp);
        }
        else
        {
            node *temp1 = new node;
            temp1->data = exp[i];
            temp1->right = s.pop();
            temp1->left = s.pop();
            s.push(temp1);
        }
    }
    p = s.pop();
}

node *ExpressionTree::getroot()
{
    return p;
}

int main()
{
    ExpressionTree obj;
    int num;
    do
    {

        obj.accept();
        obj.maketree();
        node *p = obj.getroot();
        cout << "inorder traversal : ";
        obj.inorrec(p);
        cout << endl;
        cout << "preorder traversal : ";
        obj.prerrec(p);
        cout << endl;
        cout << "postorder traversal : ";
        obj.postrrec(p);
        cout << endl;

        cout << endl;
        cout << "Iterative inorder : ";
        obj.inorder(p);
        cout << endl;
        cout << "Iterative preorder : ";
        obj.preorder(p);
        cout << endl;
        cout << "Iterative postorder : ";
        obj.postorder(p);
        cout << "Enter 1 to continue" << endl;
        cin >> num;
        cout << endl;
    } while (num == 1);

    return 0;
}