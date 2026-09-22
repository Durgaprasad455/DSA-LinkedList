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

//insert at head
Node* insertHead(Node* head,int val){
  Node* temp=new Node(val,head);
  return temp;
}

//insert at tail
Node* insertTail(Node* head,int val){
  if(head==NULL) return new Node(val);
  Node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  Node* newNode=new Node(val,NULL);
  temp->next=newNode;
  return head;
}

// inserting at given kth element
Node* insertPositionK(Node* head,int el,int k){
  if(head==NULL){
    if(k==1) return new Node(el);
    else return NULL;
  }
  if(k==1){
    Node* temp=new Node(el,head);
    return temp;
  }
  int cnt=0;
  Node* temp=head;
  while(temp!=NULL){
    cnt++;
    if(cnt==k-1){
      Node* x=new Node(el);
      x->next=temp->next;
      temp->next=x;
      break;
    }
    temp=temp->next;
  }
  return head;
}
//insert at before the value

Node* insertBeforeValue(Node* head,int el,int val){
  if(head==NULL){
    return NULL;
  }
  if(head->data==val){
    return new Node(el,head);
  }
  Node* temp=head;
  while(temp->next!=NULL){
    if(temp->next->data==val){
      Node* x=new Node(el);
      x->next=temp->next;
      temp->next=x;
      break;
    }
    temp=temp->next;
  }
  return head;
}


int main(){
  vector<int>a{10,2,30,4,50};
  Node* head=convertArr2LL(a);
  head=insertBeforeValue(head,100,10);
  print(head);
}