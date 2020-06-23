//Implement kReverse(int k) i.e. you reverse first k elements then reverse next k elements and so on
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

struct ll {
    node *head;
    node *tail;
};

ll reverse(node *head) {

    if(head == NULL) {
        ll ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    if(head->next == NULL) {
        ll ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    ll smallAns = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    smallAns.tail = head;

    return smallAns;
}

node* kReverse(node *head, int n)
{
    //write your code here

    // cout << "*" << endl;

    if(head == NULL) {
        return head;
    }

    int count = 1;
    node *t1 = head;

    while(count < n && t1 != NULL) {
        t1 = t1->next;
        count++;
    }

    node *t2;
    if(t1 != NULL) {
        t2 = t1->next;
        t1->next = NULL;

        // cout << t1->data << endl;
    }
    else {
        t2 = NULL;
    }

    ll ans = reverse(head);

    ans.tail->next = kReverse(t2, n);

    return ans.head;
}




int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=kReverse(head,n);
    print(head);
    return 0;
}
