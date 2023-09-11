// Problem Statement:
// Auxiliary Given a singly linked list, find the middle of the linked list. For example, if the given linked list is 1->2->3->4->5 then the output should be 3. 
// If there are even nodes, then there would be two middle nodes, we need to print the second middle element. 
// For example, if the given linked list is 1->2->3->4->5->6 then the output should be 4. 

// Problem Solution:
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

class NodeOperation{
public:
	// Function to add a new node
	void pushNode(class Node** head_ref,int data_val){
		
		// Allocate node
		class Node *new_node = new Node();
		// Put in the data
		new_node->data = data_val;
		// Link the old list of the new node
		new_node->next = *head_ref;
		// move the head to point to the new node
		*head_ref = new_node;
	}
};

int main() {
class Node *head = NULL;
	class NodeOperation *temp = new NodeOperation();
	for(int i=5; i>0; i--){
		temp->pushNode(&head, i);
	}
	vector<int>v;
	while(head!=NULL){
	v.push_back(head->data);
	head=head->next;
	}
	cout<<"Middle Value Of Linked List is :";
	cout<<v[v.size()/2]<<endl;
	return 0;
}
