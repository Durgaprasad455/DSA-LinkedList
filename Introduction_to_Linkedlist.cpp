#include<bits/stdc++.h>
using namespace std;

// concept
/*  A Linked List is a linear data structure in which 
    elements are stored in separate memory locations called nodes.
    Each node contains data and a link (pointer) to the next node.

    -> Data: The actual value stored in the node.
    -> Next: A pointer that stores the address of the next node.

    Types
    1)single linkedlist
    2)doubly linkedlist
    3)circular linkedlist
    4)circular doubly linkedlist

*/
// Creating a node in c++
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

int main(){
  vector<int>a{1,2,3,4};
  Node* y=new Node(a[0],nullptr);
  cout<<y->data;
}
