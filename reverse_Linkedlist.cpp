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

// Iterative solution 
// Brute Force TC -> O(2N) , SC-> O(N) for stack data structure 
Node* iterativeBrute(Node* head){
  Node* temp=head;
  stack<int>st;
  while(temp!=NULL){
    st.push(temp->data);
    temp=temp->next;
  }
  temp=head;
  while(temp!=NULL){
    temp->data=st.top();
    st.pop();
    temp=temp->next;
  }
  return head;
}

//Optimal solution TC->o(n) , sc->o(1)
Node* iterativeOptimal(Node* head){
  Node* temp=head;
  Node* prev=NULL;
  while(temp!=NULL){
    Node* front=temp->next;
    temp->next=prev;
    prev=temp;
    temp=front;
  }
  Node* newHead=prev;
  return newHead;
}

// recursive solution 
// TC - > O(N) , SC -> O(N) -> recursive stack space
Node* recursiveSolution(Node* head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node* newHead=recursiveSolution(head->next);
  Node* front=head->next;
  front->next=head;
  head->next=NULL;
  return newHead;
}

int main(){
  vector<int>a{1,2,3,4,5};
  Node* head=convertArr2LL(a);
  head=recursiveSolution(head);
  print(head);
}