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
    mover->next=temp;;
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

Node* intersectionPoint(Node* head1, Node* head2) {

    map<Node*,int> mp;

    Node* temp = head1;

    while (temp != NULL) {
        mp[temp] = 1;
        temp = temp->next;
    }

    temp = head2;

    while (temp != NULL) {
        if (mp.find(temp) != mp.end()) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}
// TC -> O(N1+ 2N2) , SC -> O(1)
Node* intersectionY(Node* head1,Node* head2){
  Node* temp1=head1;
  Node* temp2=head2;
  int N1=0;
  int N2=0;
  while(temp1!=NULL){
    N1++;
    temp1=temp1->next;
  }
  while(temp2!=NULL){
    N2++;
    temp2=temp2->next;
  }
  if(N1<N2){
    return collisionPoint(head1,head2,N2-N1);
  }
  else{
    return collisionPoint(head2,head1,N1-N2);
  }
}
Node* collisionPoint(Node* temp1,Node* temp2,int d){
  while(d){
    d--;
    temp2=temp2->next;
  }
  while(temp1!=temp2){
    temp1=temp1->next;
    temp2=temp2->next;
  }
  return temp1;
}

// Optimal solution TC -> O(N1+N2) , SC-> O(1)
Node* optimalSolution(Node* head1,Node* head2){
  Node* t1=head1;
  Node* t2=head2;
  while(t1!=t2){
    t1=t1->next;
    t2=t2->next;
    if(t1==t2) return t1;
    if(t1==NULL) t1=head2;
    if(t2==NULL) t2=head1;
  }
  return t1;
}

int main(){
  
}