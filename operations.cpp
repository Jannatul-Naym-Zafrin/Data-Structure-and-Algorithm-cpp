#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head=NULL;

void insertlast(int val)
{
    node* newNode= new node();
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    else{
        node* current=head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newNode;
        
    }
}

void insert_at_Begining(int val)
{
    node* newNode= new node();
    newNode->data=val;
    newNode->next=head;
    head=newNode;

}

void insert_at_Any(int val,int target)
{
    node* newNode= new node();
    if(!newNode) //memory allocation check
    {
        cout<<"memory alllocation failed."<<endl;
        return;
    }
    newNode->data=val;
    newNode->next=NULL;

    if(head==NULL){   //empty list
        cout<<"target "<<target<<"not found as the list is empty."<<endl;
        return;
    }
    else{
        node* current=head;
        bool targetFound= false;

        while(current!=NULL){
            if(current->data==target){
                newNode->next=current->next;
                current->next=newNode;
                target= true;
                return;
               
            }
            else{
                 current=current->next;
            }

        }
        if(!targetFound){
            cout<<"target value "<<target<<" not found in the list."<<endl;
            delete newNode;
        }
        
    }
}

void delete_begin()
{
    if(head==NULL){
        return;
    }
    head=head->next;
}

void delete_at_any(int target)
{
    node* current=head;
    node* prev=NULL;
     if(head==NULL){
        return;
    }

    while(current->data!=target){
        prev=current;
        current=current->next;
    }
    prev->next=current->next;

}

void delete_last()
{
    node* current=head;
    node* prev=NULL;

    if(head==NULL){
        return;
    }

    while(current->next!=NULL){
        prev=current;
        current=current->next;
    }
    prev->next=NULL;
}

void printList()
{
        node* current=head;
        while(current!=NULL){
            cout<<current->data<<endl;
            current=current->next;
        }
}

int main()
{
    insertlast(20);
    insertlast(10);
    insertlast(10);

    cout<<"printing the list: "<<endl;
    printList();

    insert_at_Begining(30);
     cout<<"printing the list: "<<endl;
    printList();

    insert_at_Any(15,10);
     cout<<"printing the list: "<<endl;
    printList();

    delete_at_any(10);
    cout<<"printing the list: "<<endl;
    printList();

    getchar();
}