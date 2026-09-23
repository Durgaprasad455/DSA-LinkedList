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

// Remove Nth Node from the end of LL (Brute Force)
// TC -> O(Len) + O(len-n)  , SC->O(1)
Node* bruteForce(Node* head,int n){
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node* temp=head;
  int cnt=0;
  while(temp!=NULL){
    cnt++;
    temp=temp->next;
  }
  int res=cnt-n;
  temp=head;
  if(res==0){
    Node* newHead=head->next;
    delete head;
    return newHead;
  }
  while(temp!=NULL){
    res--;
    if(res==0){
      break;
    }
    temp=temp->next;
  }
  Node* delNode=temp->next;
  temp->next=temp->next->next;
  delete delNode;
  return head;
}
//optimal solution
//TC->O(Len) , SC->O(1)
Node* optimalSolution(Node* head,int n){
  Node* fast=head;
  Node* slow=head;
  for(int i=0;i<n;i++){
    fast=fast->next;
  }
  if(fast==NULL){
    return head->next;;
  }
  while(fast->next!=NULL){
    fast=fast->next;
    slow=slow->next;
  }
  Node* delNode=slow->next;
  slow->next=fast;
  delete delNode;
  return head;
}

int main(){
  vector<int>a{1,2,3,4,5};
  Node* head=convertArr2LL(a);
  head=optimalSolution(head,5);
  print(head);
}