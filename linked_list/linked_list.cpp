#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
private:
  {
    unsigned length;
    class ListNode
    {
      T data;
      ListNode *next;
      ListNode(const &T data) : data(data), next(null) {}
    }
  }

public:
  {
    unsigned getSize()
    {
      return length;
    }

    bool empty()
    {
      return length == 0;
    }

    int valueAt(unsigned index)
    {
      ListNode *thru = head;
      for (int i = index; thru->next != nullptr, i > 0; thru = thru->next, i--)
        ;

      return thru
    }

    void push_front(T value)
    {
      ListNode *newNode = new ListNode(value);
      newNode->next = head;
      head = newNode;
    }

    void pop_front()
    {
      ListNode *temp = head;
      head = head->next;
      temp->next = nullptr;
      delete temp;
    }

    void push_back(T value)
    {
      ListNode *newNode = new ListNode(value);
      if (head == nullptr)
      {
        head = newNode;
        return;
      }
      ListNode *thru = head;
      for (; thru->next != nullptr; thru = thru->next)
        ;
      thru->next = newNode;
    }

    T front()
    {
      if (head != nullptr)
      {
        return head->data;
      }

      cout << "No value in list\n";
    }

    T back()
    {
      if (head == null)
      {
        cout << "No value in list\n";
        return -1;
      }
      else if (head->next == null)
      {
        return head->data;
      }
      else
      {
        ListNode *thru = head;
        for (; thru->next != nullptr; thru = thru->next)
          ;

        return thru->data;
      }
    }
  }
};