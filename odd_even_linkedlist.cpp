#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node(int data1,Node* next1){
    data=data1;
    next=next1;
  }
  Node(int data1){
    data=data1;
    next=nullptr;
  }
};

Node* convertArr2LL(vector<int>&a){
  Node* head=new Node(a[0]);
  Node* mover=head;
  for(int i=1;i<a.size();i++){
    Node* temp=new Node(a[i]);
    mover->next=temp;;
    mover=temp;
  }
  return head;
}
void print(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
 
// Brute Force Solution TC-> O(2N) , SC-> O(N)
Node* oddEvenLL(Node* head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  vector<int>ls;
  Node* temp=head;
  while(temp!=NULL && temp->next!=NULL){
    ls.push_back(temp->data);
    temp=temp->next->next;
  }
  if(temp){
    ls.push_back(temp->data);
  }
  temp=head->next;
  while(temp!=NULL && temp->next!=NULL){
    ls.push_back(temp->data);
    temp=temp->next->next;
  }
  if(temp){
    ls.push_back(temp->data);
  }
  temp=head;
  int i=0;
  while(temp!=NULL){
    temp->data=ls[i];
    i++;
    temp=temp->next;
  }
  return head;
}

//Optimal solution TC->O(N) , SC->O(1)
Node* oddEvenOptimal(Node* head){
  if(head==NULL || head->next==NULL) return head;
  Node* odd=head;
  Node* even=head->next;
  Node* evenHead=head->next;
  while(even!=NULL && even->next!=NULL){
    odd->next=odd->next->next;
    even->next=even->next->next;

    odd=odd->next;
    even=even->next;
  }
  odd->next=evenHead;
  return head;
}

int main(){
  vector<int>a{1,2,3};
  Node* head=convertArr2LL(a);
  head=oddEvenOptimal(head);
  print(head);
}