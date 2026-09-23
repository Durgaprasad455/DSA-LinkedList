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
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}
//Brute force solution
// TC -> O(2N) , SC->O(1)
Node* bruteForce(Node* head){
  int cnt0=0;
  int cnt1=0;
  int cnt2=0;
  Node* temp=head;
  while(temp!=NULL){
    if(temp->data==0){
      cnt0++;
    }
    else if(temp->data==1){
      cnt1++;
    }else{
      cnt2++;
    }
    temp=temp->next;
  }
  temp=head;
  while(temp!=NULL){
    if(cnt0>0){
      temp->data=0;
      cnt0--;
    }
    else if(cnt1>0){
      temp->data=1;
      cnt1--;
    }else{
      temp->data=2;
      cnt2--;
    }
    temp=temp->next;
  }
  return head;
}
//Optimal solution single traversal using dummy nodes of 3
// TC -> O(N) , SC->O(1)
Node* optimalSolution(Node* head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node* dummyzero=new Node(-1);
  Node* dummyone=new Node(-1);
  Node* dummytwo=new Node(-1);
  Node* zero= dummyzero;
  Node* one=dummyone;
  Node* two=dummytwo;
  Node* temp=head;
  while(temp!=NULL){
    if(temp->data==0){
      zero->next=temp;
      zero=zero->next;
    }
    else if(temp->data==1){
      one->next=temp;
      one=one->next;
    }
    else{
      two->next=temp;
      two=two->next;
    }
    temp=temp->next;
  }
  zero->next=dummyone->next?dummyone->next:dummytwo->next;
  one->next=dummytwo->next;
  two->next=NULL;
  Node* newHead=dummyzero->next;
  return newHead;
}

int main(){
  vector<int>a{1,0,1,2,0,2,1};
  Node* head=convertArr2LL(a);
  head=optimalSolution(head);
  print(head);
}