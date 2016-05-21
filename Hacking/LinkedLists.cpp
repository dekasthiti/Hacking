#include <iostream>
#include <vector>
#include "LinkedLists.h"

using namespace std;

struct LinkedListNode
{
	LinkedListNode* next;
	int data;
}*Node;

LinkedListNode* reverseLinkedListReal(LinkedListNode* head);
LinkedListNode* reverseLinkedListRealRecursive(LinkedListNode* ptr);

void reverseLinkedList()
{
	unsigned int N;

	cout << "Enter the number of nodes you want to add to the list: ";
	cin >> N;

	// First create the list
	cout << "Enter " << N << " nodes for a linked list" << endl;

	vector<int> dataList;
	unsigned int tmp;

	for (unsigned int i = 0; i < N; i++)
	{
		cin >> tmp;
		dataList.push_back(tmp);
	}

	LinkedListNode* head = NULL; // To return head of list, insert new nodes in front

	vector<int>::iterator itr = dataList.begin();
	while (itr != dataList.end())
	{
		unsigned int data = *itr; 
		LinkedListNode* node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
		if (node != NULL)
		{
			node->data = data;
			node->next = head; // head was pointing to the previous node
			head = node;       // update head
		}
		itr++;
	}

	// Now print the list in reverse
	LinkedListNode* tmpNode = head;
	LinkedListNode* reversedHead = NULL;
	cout << "Printing the linked list in reverse" << endl;
	while (tmpNode != NULL)
	{
		cout << tmpNode->data << "->";
		tmpNode = tmpNode->next;
	}
	cout << endl;

	// However, we cheated here a bit. We assumed the list was not created and created one inserting the new 
	// nodes in the front.
	// To do this the right way, assume the list is given to you and you need to reverse it using pointer manipulation.
	reversedHead = reverseLinkedListReal(head);
	tmpNode = reversedHead;
	cout << "Printing the linked list in reverse (reverse of reverse in this case)" << endl;
	while (tmpNode != NULL)
	{
		cout << tmpNode->data << "->";
		tmpNode = tmpNode->next;
	}

	// Recursive reverse
	reversedHead = reverseLinkedListRealRecursive(reversedHead);
	tmpNode = reversedHead;
	cout << "\n`Printing the linked list in reverse recursively (reverse of reverse of reverse in this case)" << endl;
	while (tmpNode != NULL)
	{
		cout << tmpNode->data << "->";
		tmpNode = tmpNode->next;
	}

	return;
}

LinkedListNode* reverseLinkedListReal(LinkedListNode* head)
{
	LinkedListNode* curr, *prev, *next;
	LinkedListNode* reversedHead;

	// Initial state
	curr = head;
	prev = NULL;
	next = head;

	// Do work: Save current iteration state, Update link
	while(curr != NULL)
	{
		next = curr->next; // save next node
		curr->next = prev; // update current's link with prev
		prev = curr;       // save curr to prev
		curr = next;       // update current
	}
	reversedHead = prev;
	return reversedHead;

}

LinkedListNode* reversedHead = NULL;
LinkedListNode* reverseLinkedListRealRecursive(LinkedListNode* ptr)
{
	if (ptr == NULL) // this is p->next (curr)
	{
		return NULL;
	}
	if (ptr->next == NULL) //this is p->next->next (next)
	{
		reversedHead = ptr;
		return reversedHead;
	}
	// Save state for this frame
	LinkedListNode* prev = ptr;
	LinkedListNode* curr = ptr->next;

	// Traverse
	reverseLinkedListRealRecursive(curr);

	// Do work: Update links for this frame on winding back the stack
	curr->next = prev;
	prev->next = NULL;
	return reversedHead;
}