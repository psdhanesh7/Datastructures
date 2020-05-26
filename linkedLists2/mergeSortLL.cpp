//merge sort recursive
#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;

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

node* mergeTwoLLs(node *head1, node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    node *newHead;
    if(head1->data < head2->data) {
        newHead = head1;
        head1 = head1->next;
    }
    else {
        newHead = head2;
        head2 = head2->next;
    }
    
    node *curr = newHead;
    while(head1 != NULL && head2 != NULL) {
        
        if(head1->data < head2->data) {
            curr->next = head1;    
            head1 = head1->next;
        
        }else {
            curr->next = head2;
            head2 = head2->next;
        }
        
        curr = curr->next;
    }
    
    while(head1 != NULL) {
        curr->next = head1;
        
        head1 = head1->next;
        curr = curr->next;
    }
    
    while(head2 != NULL) {
        curr->next = head2;
        
        head2 = head2->next;
        curr = curr->next;
    }
    
    curr->next = NULL;
    
    return newHead;
    
}

node* mergeSort(node *head) {
    //write your code here
    
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    node *slow = head;
    node *fast = head->next;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    node *head1 = head;
    node *head2 = slow->next;
    
    slow->next = NULL;
    
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    
    head = mergeTwoLLs(head1, head2);
    
    return head;
}

int main()
{
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}

