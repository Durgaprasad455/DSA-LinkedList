#include<bits/stdc++.h>
using namespace std;

// Deletion in linked list
// deletion of head , position ,val ,tail of linkedlist

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

int LengthofLL(Node* head){
  int cnt=0;
  Node* temp=head;
  while(temp){
    temp=temp->next;
    cnt++;
  }
  return cnt;
}

Node* convertArr2LL(vector<int>&a){
  Node* head = new Node(a[0]);
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
// remove of head 
Node* deleteHead(Node* head){
  if(head==NULL) return head;
  Node* temp=head;
  head=head->next;
  delete temp;
  return head;
}

//remove of tail
Node* deleteTail(Node* head){
  if(head==NULL || head->next==NULL) return NULL;
  Node* temp=head;
  while(temp->next->next != NULL){
    temp=temp->next;
  }
  delete temp->next;
  temp->next=nullptr;
  return head;
}

//delete Kth element of LL
Node* deletePositionK(Node* head,int k){
  if(head==NULL) return head;
  if(k==1){
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
  }
  int cnt=0;
  Node* temp=head;
  Node* prev=NULL;
  while(temp!=NULL){
    cnt++;
    if(cnt==k){
      prev->next=prev->next->next;
      delete temp;
      break;
    }
    prev=temp;
    temp=temp->next;
  }
  return head;
}

// delete element
Node* deleteElement(Node* head, int val){
  if(head==NULL) return head;
  if(head->data==val){
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
  }
  Node* temp=head;
  Node* prev=NULL;
  while(temp!=NULL){
    if(temp->data==val){
      prev->next=prev->next->next;
      delete temp;
      break;
    }
    prev=temp;
    temp=temp->next;
  }
  return head;
}

int main(){
  vector<int>a{1,2,3,4,5,6};
  Node* head=convertArr2LL(a);
  head=deleteElement(head,5);
  print(head);
}