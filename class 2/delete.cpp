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
    ~Node(){
        cout<<"I am in destructor:"<<this->data<<endl;
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
void insertAtposition(Node*&head,Node*&tail,int data,int position){
    if(position<1){
        cout<<"cannot insert ! please enter a valid position "<<endl;
        return ;
    }
    int length=PrintLL(head);
    if(position>length){
        cout<<"cannot insert ! please enter a valid position "<<endl;
        return ;

    }
    if (position==1)
    {
        insertHead(head ,tail,data);
    }
    else if(position == length+1){
        // iss case me insert @tail karenge 
        insertTail(head,tail,data);
    }
    else{
        // step 1 create a node 
        Node *newnode=new Node(data);
        // traverse karao current and prev ko to current 
        Node *prev=NULL;
        Node *curr=head;
        while (position !=1)
        {
            prev=curr;
            curr=curr->next;
            position--;
        }
        prev->next=newnode;
        newnode->next=curr;
        
        
    }
    
     
    

}
void deleteNode(Node*&head,Node*&tail,int position){
    // position 1 ka case alag se handle karna padega qki head change ho raha hai usme 
    if(head==NULL){
        cout<<"linked list is empty "<<endl;
    }
    if (head==tail)
    {
        Node *temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
    }
    
    if(position==1){
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    // tail se delete karna padega 
    int len=PrintLL(head);
    if(position==len){
        // iss case me end me delte karna padega ;
        Node *prev=head;
        while (prev->next==tail)
        {
            prev=prev->next;

        }
        // previous ka link null karo 
        prev->next=NULL;
        delete tail;
        // update the tail
        tail=prev;
        }
    else{
        // middle me koi node hai usko delte karna hai to kaise karenge 
        // set the two pointer so that we can iterate through ll
        Node *prev=NULL;
        Node *curr=head;
        while (position !=1){
            prev=curr;
            curr=curr->next;
            position--;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }

}
int main()
{

    Node*head=NULL;
    Node*tail=NULL;
    
    insertHead(head,tail,10);
    insertHead(head,tail,15);
    insertHead(head,tail,20);
    insertTail(head,tail,5);
    insertAtposition(head,tail,5,2); 
    insertAtposition(head,tail,100,5);

    cout << PrintLL(head) << endl;
    deleteNode(head,tail,3);
    cout << PrintLL(head) << endl;

    return 0;
}