
/* 
 * File:   main.cpp
 * Author: Priyanka
 * Created on May 30, 2019, 2:34 PM
 */

//Singly Circular linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
};

Node *head;

void insertBegin(int data) {

    Node *temp = head;
    Node *newNode = new Node();
    newNode->data = data;

    //Insert at beginning
    newNode->next = head;

    /* If linked list is not NULL then  
   set the next of last node */
    if (head != NULL) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        newNode->next = newNode;
    }

    head = newNode;

}

void printList(Node *head) {
    Node *temp = head;
    if (head != NULL) {
        do {
            cout << temp->data << ",";
            temp = temp->next;
        } while (temp != head);
    }
    
    cout<<endl;

}

void splitList(Node **head1, Node **head2) {
    if (head == NULL) return;
    Node *slow = head;
    Node *fast = head;

    /*If there are odd number of nodes, it will be fast->next=head
     If there are even nodes, it will be fast->next->next=head*/

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next; //fast moves by two nodes at a time
        slow = slow->next; //slow moves by one node at a time
    }

    //If even nodes, move the fast pointer by one
    if (fast->next->next == head) {
        fast = fast->next;
    }

    /* Set the head pointer of first half */
    *head1 = head;

    /* Set the head pointer of second half */
    if (head->next != head)
        *head2 = slow->next;

    //Making the second half circular
    fast->next = slow->next;

    //Making the first half circular
    slow->next = head;

}
void deleteNode(int key)
{
    cout<<"Deleting "<<key<<endl;
    Node *temp=head;
    Node *cur=head;
    Node *prev;
    
    if(head==NULL) return;
    
    while(cur->data!=key)
    {
        if(cur->next==head)
        {
            cout<<"Node not found"<<endl;
            break;
        }
        prev=cur;
        cur=cur->next;
    }
    
    //Check if it is the only node
    if (head->next == head) { 
       
        head = NULL; 
        free(cur); 
        return; 
        
    } 
    
    //If more than one node
    //Check if the first node
    if(cur==head)
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        //Do not forget to set the position of head
        head=head->next;
        temp->next=head;
        free(cur);
    }
    
    //Check if the last node
    else if(cur->next==head)
    {
        prev->next=head;
        free(cur);
    }
    
    //Check if the node lies in the middle
    else
    {
        prev->next=cur->next;
        free(cur);
    }
        
    
    
}

void reverseList()
{
    if(head==NULL) return;
    
    Node *prev=NULL;
    Node *next=head;
    Node *current=head;
    
    do
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }while(current != head);
    
    //Making the first node point to last node
    head->next=prev;
    
    //Making the last node as first node;
    head=prev;
    
    
}

int main() {
    insertBegin(3);
    insertBegin(4);
    insertBegin(5);
    insertBegin(6);
    insertBegin(7);
    insertBegin(8);
    insertBegin(9);
    insertBegin(10);
    printList(head);

    //Deletion
    //Deleting 6
    deleteNode(6);
    printList(head);
    deleteNode(3);
    printList(head);
    deleteNode(9);
    printList(head);
    
    //Reverse 
    reverseList();
    printList(head);
    
    //Split a circular list into two halves
    Node *head1 = NULL;
    Node *head2 = NULL;
    splitList(&head1, &head2);
    printList(head1);
    printList(head2);
}

