//Check if a linked list is a palindrome
#include <iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//head is the head of you linked list
// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/


node* reverseLinkedList(node *head) {
    
    if(head == NULL) {
        return head;
    }
    if(head->next == NULL) {
        return head;
    }
    
    node *newHead = reverseLinkedList(head->next);
    
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

bool check_palindrome(node* head)
{
    //write your code here
    node *slow = head;
    node *fast = head->next;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    node *head2 = slow->next;
    slow->next = NULL;
    
    head2 = reverseLinkedList(head2);
    
    while(head2 != NULL) {
        if(head->data != head2->data) {
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    
    return true;
}



int main()
{
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}
