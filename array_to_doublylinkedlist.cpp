#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node* prev;

  Node(int data1,Node* next1,Node* prev1){
    data=data1;
    next=next1;
    prev=prev1;
  
  }

  Node(int data1){
    data=data1;
    next=nullptr;
    prev=nullptr;
  }
};

Node* convertArr2DLL(vector<int>&a){
  Node* head=new Node(a[0]);
  Node* prev=head;
  for(int i=1;i<a.size();i++){
    Node* temp=new Node(a[i],nullptr,prev);
    prev->next=temp;
    prev=temp;
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

int main(){
  vector<int>a{1,2,3,4,5};
  Node* head=convertArr2DLL(a);
  print(head);
  return 0;
}