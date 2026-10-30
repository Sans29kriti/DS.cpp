#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
    int data;
    struct node*next;
};
struct node *start=NULL,*ptr,*pptr;
int val;
void display(){
ptr=start;
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
            ptr = ptr->next;
    }    
    cout<< "NULL";
}
void createnode(){
    cout<<"input value to insert";
    cin>>val;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(start ==NULL)
        start = newnode;
    else{
        ptr=start;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newnode;
    }
}
void deletionlast()
{pptr=NULL;
ptr=start;
while(ptr->next!=NULL)
{
    pptr=ptr;
    ptr=ptr->next;
}
        pptr->next=NULL;
}
int main(){
    int n;
    cout<<"number of nodes;";
    cin>>n;
    for(int i = 0;i<n;i++)
        {
            createnode();
        }
    cout<<"existing linked list is";
    display(); 
    cout<<"\nnow deletion  value at last\n";
    deletionlast();
    cout<<"after deletion at last";
    display();
    cout<<"\nfreezing memory.....";
    ptr=start;
        while(ptr!=NULL){
        struct node *nextnode=ptr->next;
        free(ptr);
        ptr= nextnode;
    }
    start=NULL;
    return 0;
};
