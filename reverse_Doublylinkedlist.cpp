#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* prev;
  Node* next;
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

// here we just store all data in stack replace in reverse order in
// linkedlist ,so we are just changing data in nodes
// TC-> O(2N) SC-> O(N)
Node* reverseDLL(Node* head){
  Node* temp=head;
  stack<int>st;
  while(temp!=NULL){     //O(N)
    st.push(temp->data);
    temp=temp->next;
  }                         //stack={1,2,3,4,5->top} LIFO 
  temp=head;
  while(temp!=NULL){
    temp->data=st.top();    // O(N) Top->5
    st.pop();            //Top->4 as 5 is poped out continues
    temp=temp->next;
  }
  return head;
}

// we don't change values just reverse the links in one traversal
// TC-> O(N) , SC-> O(1)
Node* optimalReverseDLL(Node* head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node*last=NULL;
  Node* current=head;
  while(current!=NULL){
    last=current->prev;
    current->prev=current->next;
    current->next=last;
    current=current->prev;
  }
  Node* newHead=last->prev;
  return newHead;

}
int main(){
  vector<int>a{1,7,3,9,5};
  Node* head=convertArr2DLL(a);
  head=optimalReverseDLL(head);
  print(head);
}