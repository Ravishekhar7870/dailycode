#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};
void Insertattail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
} 
void Insertathead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}
void Insert(Node* head,int data,int position){
    Node* newnode = new Node(data);
    Node* temp=head;
    
    int cnt=1;
    while(cnt<position-1){
         temp=temp->next;
         cnt++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void deletenode(Node* &head,int pos,Node* &tail){
    
    if(pos==1){
        Node* temp=head;
        head=head->next;\
        temp->next=NULL;
        free(temp);
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next=curr->next;
        if(curr->next==NULL){
            tail=prev;
        }
        curr->next=NULL;
        free(curr);
    }
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    Insertathead(head,15);
    Insertattail(tail,34);
    Insertattail(tail,23);
    Insert(head,35,2);
    Insert(head,43,4);
    deletenode(head,6,tail);
    cout<<head->data<<" "<<tail->data<<endl;
    print(head);
}
