#include <iostream>
#include <vector>
struct LinkedListNode
{
	LinkedListNode* next;
	int data;
}*Node;

using namespace std;
LinkedListNode* reverseLinkedListReal(LinkedListNode* head);
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

	return;
}

LinkedListNode* reverseLinkedListReal(LinkedListNode* head)
{
	LinkedListNode* curr, *prev, *next;

	curr = head;
	prev = NULL;
	next = head;
	while(curr != NULL)
	{
		next = curr->next; // save next node
		curr->next = prev; // update current's link with prev
		prev = curr;       // save curr to prev
		curr = next;       // update current
	}
	head = prev;
	return head;

}