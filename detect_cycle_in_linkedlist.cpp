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

bool cycleDetect(Node* head){
  Node* slow=head;
  Node* fast=head;
  while(fast && fast->next){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){
      return true;
    }
  }
  return false;
}

int main(){
  vector<int>a{1,2,3,4,5};
  Node* head=convertArr2LL(a);
  // 5 → 3
  Node* temp = head;
  Node* third = head->next->next;

  while(temp->next != nullptr){
      temp = temp->next;
  }

  temp->next = third;
  bool ans=cycleDetect(head);
  if(ans){
    cout<<"cycle exist"<<endl;
  }
  else{
    cout<<"cycle not exist"<<endl;
  }
}