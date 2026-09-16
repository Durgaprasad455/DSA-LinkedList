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

//length TC->O(N)
int LengthOfLL(Node* head){
  int cnt=0;
  Node* temp=head;
  while(temp){
    temp=temp->next;
    cnt++;
  }
  return cnt;
}

int main(){
  vector<int>a{1,2,3,4,5};
  Node* head=convertArr2LL(a);
  cout<<LengthOfLL(head);
}