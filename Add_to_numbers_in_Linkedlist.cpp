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
//add numbers of linkedlists l1 and l2 and output is sumlist of l1+l2
//TC-> O(ma(N1,N2)) , SC-> O(max(N1,N2))
Node* addLists(Node* head1,Node* head2){
  Node* temp1=head1;
  Node* temp2=head2;
  Node* dummyNode=new Node(-1);
  Node* curr=dummyNode;
  int carry=0;
  while(temp1!=NULL || temp2!=NULL){
    int sum=carry;
    if(temp1){
      sum=sum+temp1->data;
    }
    if(temp2){
      sum=sum+temp2->data;
    }
    Node* newNode= new Node(sum%10);
    carry=sum/10;
    curr->next=newNode;
    curr=curr->next;
    if(temp1){
      temp1=temp1->next;
    }
    if(temp2){
      temp2=temp2->next;
    }
  }
  if(carry){
    Node* newNode=new Node(carry);
    curr->next=newNode;
  }
  return dummyNode->next;
}

int main(){
  vector<int>a{3,5};
  vector<int>b{4,5,9,9};
  Node* head1=convertArr2LL(a);
  Node* head2=convertArr2LL(b);
  Node* head=addLists(head1,head2);
  print(head);

}