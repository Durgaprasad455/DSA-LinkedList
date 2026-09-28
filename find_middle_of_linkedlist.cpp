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
    mover->next=temp;
    mover=temp;
  }
  return head;
}

void print(Node* head){
  while(head){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}

Node* middleEL(Node* head){
  Node* slow=head;
  Node* fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow;
}

int main(){
  vector<int>a{1,2,3,4,5,6};
  Node* head=convertArr2LL(a);
  Node* middle=middleEL(head);
  cout<<middle->data<<endl;
}