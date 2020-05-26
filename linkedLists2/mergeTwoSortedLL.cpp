#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

Node* mergeTwoLLs(Node *head1, Node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    Node *newHead;
    if(head1->data < head2->data) {
        newHead = head1;
        head1 = head1->next;
    }
    else {
        newHead = head2;
        head2 = head2->next;
    }
    
    Node *curr = newHead;
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

int main() {
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}

