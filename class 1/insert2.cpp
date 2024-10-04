#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        // cout<<"I am in default constructor"<<endl;
        this->next = NULL;
    }
    Node(int data)
    {
        // cout<<"I am inside parameterised constructor"<<endl;
        this->data = data;
        this->next = NULL;
    }
};
void insertTail(Node *&head,Node *&tail,int data){
    if (head == NULL)
    {
        // 2 step process
        // 1.create a new node
        Node *endnode = new Node(data);
        // 2.point head to new node
        head = endnode;
        // single element hai to head and tail ek hi jagah hoga 
        tail=endnode;
    }
    else{
        // creating a node 
        Node *endnode=new Node(data);
        // making tail node 
        tail->next=endnode;
        tail=endnode;

    }

}
void insertHead(Node *&head,Node *&tail,int data)
{
    if (head == NULL)
    {
        // 2 step process
        // 1.create a new node
        Node *newnode = new Node(data);
        // 2.point head to new node
        head = newnode;
        // single element hai to head and tail ek hi jagah hoga 
        tail=newnode;
    }
    else
    {
        // create a new node

        Node *newnode = new Node(data);
        // now connect newnodewith head

        newnode->next = head;
        // now make head as the primary node for further convinence 
        head = newnode;
    }
}
int PrintLL(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        length++;
    }

    cout << endl;
    return length;
}

int main()
{
    // Node *first = new Node(10);
    // Node *second = new Node(20);
    // Node *third = new Node(30);
    // Node *fourth = new Node(40);
    // Node *fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // Node *head = first;
    // Node *tail=fifth;
    Node*head=NULL;
    Node*tail=NULL;
    insertHead(head,tail,5);
    insertHead(head,tail,10);
    insertHead(head,tail,15);
    insertHead(head,tail,20);
    insertTail(head,tail,5);

    cout << PrintLL(head) << endl;
    return 0;
}