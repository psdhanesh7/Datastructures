//bubble sort iterative
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

int length(node *head) {

    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }

    return len;
}

node* swap(node *head, node* curr, node* prev, node* next) {

    if(prev == NULL) {
        curr->next = next->next;
        next->next = curr;
        return next;
    }

    prev->next = next;
    curr->next = next->next;
    next->next = curr;

    return head;
}

node* bubble_sort_LinkedList_itr(node* head)
{
    //write your code here
    if(head == NULL) {
        return head;
    }

    int n = length(head);
    node *curr, *prev, *next;

    for(int i = 0; i < n-1; i++) {
        curr = head;
        prev = NULL;

        // cout << curr->data << endl;

        while(curr->next != NULL) {            
            next = curr->next;
            if(curr->data > next->data) {
                head = swap(head, curr, prev, next);
                prev = next;
            }
            else {
                prev = curr;
                curr = next;
            }
        }
    }

    return head;
}

int main()
{
    node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}
