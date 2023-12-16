#include <iostream>

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
      void push(T x);
      T pop();
      bool isEmpty();
      T peep();
      Stack()
      {

            tos = NULL;
      }
};
template <typename T>
void Stack<T>::push(T x)
{

      Node<T> *temp = new Node<T>;
      if (tos == NULL)
      {
            tos = temp;
      }
      else
      {

            temp->next = tos;
            tos = temp;
      }
      temp->element = x;
}
template <typename T>
T Stack<T>::peep()
{

      if (isEmpty())
      {

            return 0;
      }
      else
      {

            return tos->element;
      }
}
template <typename T>
T Stack<T>::pop()
{

      if (isEmpty())
      {

            return 0;
      }
      else
      {

            Node<T> *temp = tos;
            tos = tos->next;
            T x = temp->element;
            return x;
      }
}
template <typename T>
bool Stack<T>::isEmpty()
{

      if (tos == NULL)
      {
            return true;
      }
      else
      {

            return false;
      }
}
