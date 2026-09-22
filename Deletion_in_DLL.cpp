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
// Deletion of head Node
Node* deleteHead(Node* head){
  if(head==NULL || head->next==NULL){
    return NULL;
  }
  Node* temp=head;
  head=head->next;
  head->prev=nullptr;
  temp->next=nullptr;
  delete temp;
  return head;
}

// Deletion of Tail
Node* deleteTail(Node* head){
  if(head==NULL || head->next==NULL){
    return NULL;
  }
  Node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  Node* back=temp->prev;
  back->next=nullptr;
  temp->prev=nullptr;
  delete temp;
  return head;
}

//Deletion of Kth element
Node* deleteKthElement(Node* head,int k){
  if(head==NULL){
    return NULL;
  }
  int cnt=0;
  Node* Knode=head;
  while(Knode!=NULL){
    cnt++;
    if(cnt==k) break;
    Knode=Knode->next;
  }
  Node* back=Knode->prev;
  Node* front=Knode->next;

  if(front==NULL && back==NULL){
    return NULL;
  }
  else if(front==NULL){
    return deleteTail(head);
  }
  else if(back==NULL){
    return deleteHead(head);
  }
  back->next=front;
  front->prev=back;

  Knode->prev=nullptr;
  Knode->next=nullptr;
  delete Knode;
  return head;
}

//Deletion of a Node
void deleteNode(Node* temp){
  Node* back=temp->prev;
  Node* front=temp->next;
  if(front==NULL){
    back->next=nullptr;
    temp->prev=nullptr;
    delete temp;
    return;
  }
  back->next=front;
  front->prev=back;

  temp->next=nullptr;
  temp->prev=nullptr;
  delete temp;
}

int main(){
  vector<int>a{10,20,30,40,50};
  Node* head=convertArr2DLL(a);
  deleteNode(head->next->next);
  print(head);
  return 0;
}