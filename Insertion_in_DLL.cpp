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
//insertion in Doubly LinkedList
// insert before the head 
Node* insertBeforeHead(Node* head,int val){
  Node* newHead=new Node(val,head,nullptr);
  head->prev=newHead;
  return newHead;
}
//insert after the head
Node* insertAfterHead(Node* head,int val){
  Node* temp=head->next;
  Node* newNode=new Node(val,temp,head);
  head->next=newNode;
  temp->prev=newNode;
  return head;
}

//insert before tail
Node* insertBeforeTail(Node* head,int val){
  if(head->next==NULL){
    return insertBeforeHead(head,val);
  }
  Node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  Node* back=temp->prev;
  Node* newNode=new Node(val,temp,nullptr);
  back->next=newNode;
  temp->prev=newNode;
  return head;
}
// insert after tail
Node* insertAfterTail(Node* head,int val){
  Node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  Node* newNode=new Node(val,nullptr,temp);
  temp->next=newNode;
  return head;
}
// insert Before Kth element
Node* insertBeforeKthElement(Node* head,int val,int k){
  if(head==NULL){
    return NULL;
  }
  if(head->next==NULL || k==1){
    return insertBeforeHead(head,val);
  }
  Node* temp=head;
  int cnt=0;
  while(temp!=NULL){
    cnt++;
    if(cnt==k){
      break;
    }
    temp=temp->next;
  }
  Node* back=temp->prev;
  Node* newNode=new Node(val,temp,back);
  back->next=newNode;
  temp->prev=newNode;
  return head;
}
//insert before give node element
void insertBeforeNode(Node* node,int val){
  Node* back=node->prev;
  Node* newNode=new Node(val,node,back);
  back->next=newNode;
  node->prev=newNode;
}


int main(){
  vector<int>a{1,2,3,4,5};
  Node* head=convertArr2DLL(a);
  insertBeforeNode(head->next->next,11);
  print(head);
  return 0;
}