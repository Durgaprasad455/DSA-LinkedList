#include<bits/stdc++.h>
using namespace std;
// theory
/* 
Definition

A Doubly Linked List (DLL) is a linear data structure in which each node contains three parts:

1) Previous pointer (prev) → points to the previous node.
2) Data (data) → stores the actual value.
3) Next pointer (next) → points to the next node.

prev<---Node---->next

examples real world
1) browser
2) music player
3) undo/redu
4) Image Gallery

*/
// structure of a node in Doubly Linked List
struct Node{
  int data;
  Node* prev;
  Node* next;

  Node(int data1){
    data=data1;
    prev=nullptr;
    next=nullptr;
  }
};
int main(){
  vector<int>a{1,2,3,4,5};
}