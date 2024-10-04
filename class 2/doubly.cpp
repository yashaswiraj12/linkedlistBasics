#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        // parameter nahih diya to ye constructor call hoga
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data)
    {
        // parameeter diya to ye constructor call hoga
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int findlength(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
void InsertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        // create a new node
        Node *newnode = new Node(data);
        // link  the new node with head node add head->prev to new node
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void InsertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *endnode = new Node(data);
        // now head and tail should be pointed on the endnode
        head = endnode;
        tail = endnode;
    }
    else
    {
        // create a new node
        Node *endnode = new Node(data);
        tail->next = endnode;
        endnode->prev = tail;
        tail = endnode;
    }
}
void InsertAtposition(Node *&head, Node *tail, int data, int position)
{
    if (position < 1)
    {
        cout << "cannot insert @ this position " << endl;
        return;
    }
    int length = findlength(head);
    if (position == length + 1)
    {
        InsertAtTail(head, tail, data);
    }
    if (position == 1)
    {
        InsertAtHead(head, tail, data);
    }
    else
    {
        // step 1 create a node
        Node *newnode = new Node(data);
        // set current and previous pointer
        Node *currnode = head;
        Node *prevnode = NULL;
        while (position != 1)
        {
            prevnode = currnode;
            currnode = currnode->next;
            position--;
        }
        prevnode->next = newnode;
        newnode->prev = prevnode;
        newnode->next = currnode;
        currnode->prev = newnode;
    }
}
void DeleteAtanyposition(Node *&head, Node *tail, int position)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (position < 1)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (head == tail)
    {
        // single element case regarding this
        Node *temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    int length = findlength(head);
    if (position == 1)
    {
        // we are deleteing node from head
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    if (position == length)
    {
        // we are deleting node  from tail
        Node *previousnode = tail->prev;
        previousnode->next = NULL;
        tail->prev = NULL;
        delete tail;

        // update tail a
        tail = previousnode;
    }
    else
    {
        // delete from middle
        // set previous node ,current node and next node
        Node *prevnode = NULL;
        Node *currentnode = head;
        Node *nextnode = NULL;
        while (position != 1)
        {
            prevnode = currentnode;
            currentnode = currentnode->next;
            position--;
        }
        nextnode = currentnode->next;
        prevnode->next = nextnode;
        currentnode->next = NULL;
        currentnode->prev = NULL;
        nextnode->prev = prevnode;
        delete currentnode;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    InsertAtHead(head, tail, 10);
    InsertAtHead(head, tail, 20);
    InsertAtTail(head, tail, 70);
    InsertAtTail(head, tail, 80);
    InsertAtTail(head, tail, 100);
    InsertAtposition(head, tail, 90, 3);

    print(head);
    cout<<" "<<endl;
    DeleteAtanyposition(head, tail, 3);
    print(head);

    return 0;
}