#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(){
        // cout<<"I am in default constructor"<<endl;
        this->next=NULL;

    }
    Node(int data){
        // cout<<"I am inside parameterised constructor"<<endl;
        this->data=data;
        this->next=NULL;


    }
};
int PrintLL(Node *head){
    Node*temp=head;
    int length=0;
    while (temp !=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        length++;
    }

    cout<<endl;
    return length;
    
}
int main(){
    Node*first=new Node(10);
    Node*second=new Node(20);
    Node*third=new Node(30);
    Node*fourth=new Node(40);
    Node*fifth=new Node(50);
    

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    Node* head=first;
    cout<<PrintLL(head)<<endl;
    return 0;
}