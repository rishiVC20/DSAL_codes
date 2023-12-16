//Rishikesh Chaudhari
//E11 23304

//To implement circular queue using Array as a linear Data structure

#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node
{
    T element;
    Node *next;
};

template <typename T>
class Stack
{
private:
    Node<T> *tos;

public:
    Stack()
    {
        tos = NULL;
    }
    void push(T x);
    T peep();
    T pop();
    bool isEmpty();
};

template <typename T>
void Stack<T>::push(T x)
{
    Node<T> *temp = new Node<T>;
    if (tos == NULL)
        tos = temp;
    else
    {
        temp->next = tos;
        tos = temp;
    }
    temp->element = x;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    if (tos == NULL)
        return true;
    else
        return false;
}

template <typename T>
T Stack<T>::peep()
{
    if (isEmpty())
        return 0;
    else
        return tos->element;
}

template <typename T>
T Stack<T>::pop()
{
    if (isEmpty())
        return 0;
    else
    {
        Node<T> *temp = tos;
        tos = tos->next;
        T x = temp->element;
        return x;
    }
}
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    return 0;
}

string infixToPostfix(string exp)
{
    Stack<char> s1;
    s1.push(NULL);
    string ans = "";
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            ans += c;
        }
        else if (c == '(')
        {
            s1.push(c);
        }
        else if (c == ')')
        {
            while (s1.peep() != '(')
            {
                ans += s1.peep();
                s1.pop();
            }
            s1.pop();
        }
        else
        {
            while (!s1.isEmpty() && precedence(c) <= precedence(s1.peep()))
            {
                ans += s1.peep();
                s1.pop();
            }
            s1.push(c);
        }
    }
    while (s1.peep() != NULL)
    {
        ans += s1.peep();
        s1.pop();
    }
    cout << ans << endl;
    return ans;
}

string reverse(string str)
{
    string ans = "";
    for (int i = str.length(); i >= 0; i--)
    {
        ans += str[i];
    }
    return ans;
}

string infixToPrefix(string exp)
{
    string result = reverse(exp);
    for (int i = 0; i < result.length(); i++)
    {
        if (result[i] == '(')
            result[i] = ')';
        else if (result[i] == ')')
            result[i] = '(';
    }
    Stack<char> s2;
    s2.push(NULL);
    string ans = "";
    for (int i = 0; i < result.length(); i++)
    {
        char c = result[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            ans += c;
        }
        else if (c == '(')
        {
            s2.push(c);
        }
        else if (c == ')')
        {
            while (s2.peep() != '(')
            {
                ans += s2.peep();
                s2.pop();
            }
            s2.pop();
        }
        else
        {
            while (!s2.isEmpty() && precedence(c) < precedence(s2.peep()))
            {
                ans += s2.peep();
                s2.pop();
            }
            s2.push(c);
        }
    }
    while (s2.peep() != NULL)
    {
        ans += s2.peep();
        s2.pop();
    }
    // cout<<reverse(ans)<<endl;
    return reverse(ans);
}

double postfixEvaluation(string exp)
{
    Stack<double> s3;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            double a;
            cout << "Enter value of " << c << " : ";
            cin >> a;
            s3.push(a);
        }
        else
        {
            double ans;
            double right = s3.pop();
            double left = s3.pop();
            switch (c)
            {
            case '*':
                ans = left * right;
                break;

            case '+':
                ans = left + right;
                break;

            case '-':
                ans = left - right;
                break;

            case '/':
                ans = left / right;
                break;

            case '^':
                ans = pow(left, right);
                break;
            }
            s3.push(ans);
        }
    }
    // cout<<s3.peep()<<endl;
    return s3.peep();
}

double prefixEvaluation(string str)
{
    string rev = reverse(str);
    double ans = postfixEvaluation(rev);
    // cout<<ans<<endl;
    return ans;
}

int main()
{
    cout << "--------------------WELCOME TO INFIX PROGRAM-----------------" << endl;
    cout << "Enter Suitable infix expression : ";
    string expression;
    cin >> expression;
    string ans1, ans2, ans5, ans7;
    double ans3, ans4, ans6;
    int choice, ch;
    do
    {
        cout << "1. Infix to Postfiix\n2. Infix to Prefix\n3. PostFix Evaluation\n4.Prefix Evaluation" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Infix to Postfix " << endl;
            ans1 = infixToPostfix(expression);
            cout << ans1;
            cout << endl;
            break;

        case 2:
            cout << "Infix to Prefix " << endl;
            ans2 = infixToPrefix(expression);
            cout << ans2;
            cout << endl;
            break;

        case 3:
            cout << "Postfix Evaluation " << endl;
            ans5 = infixToPostfix(expression);
            ans6 = postfixEvaluation(ans5);
            cout << ans6;
            cout << endl;
            break;

        case 4:
            cout << "Prefix Evaluation " << endl;
            ans7 = infixToPrefix(expression);
            ans6 = prefixEvaluation(ans7);
            cout << ans6;
            cout << endl;
            break;

        default:
            cout << "Incorrect choice" << endl;
            break;
        }
        cout << "Enter 1 to continue ";
        cin >> ch;
    } while (ch == 1);
}