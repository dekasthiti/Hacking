#include <iostream>
#include <vector>
#include <unordered_set> // for duplicate nodes
#include "LinkedLists.h"

using namespace std;

struct LinkedListNode
{
	LinkedListNode* next;
	int data;
}*Node;

LinkedListNode* reverseLinkedListReal(LinkedListNode* head);
LinkedListNode* reverseLinkedListRealRecursive(LinkedListNode* ptr);
void partitionLinkedList(LinkedListNode* head, int x);
void removeDuplicateNodes(LinkedListNode* &head);


void main_LinkedList()
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

	// partition list
	partitionLinkedList(reversedHead, 5);
	//tmpNode = reversedHead;
	//cout << "\n`Printing the linked list after partition" << endl;
	//while (tmpNode != NULL)
	//{
	//	cout << tmpNode->data << "->";
	//	tmpNode = tmpNode->next;
	//}

	removeDuplicateNodes(reversedHead);
	
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


/*Partition a linked list around x such that all nodes smaller than x are to the left of it
 and all nodes bigger than x are to the right of it.
 Current plan is to change the linked list in place*/

/*void partitionLinkedList(LinkedListNode* head, int x)
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}
	else
	{
		//Traverse the list till you find the node with x
		LinkedListNode* saveHead = head;
		unsigned int position = 0;
		LinkedListNode* xNode = head;
		bool found = false;
		while (xNode->next != NULL)
		{
			if (xNode->data == x)
			{
				found = true;
				break;
			}
			else
			{
				position++;
				xNode = xNode->next;
			}
		}

		if (found == true)
		{
			// Scan from head again. 
			LinkedListNode* insertBigger = xNode;
			LinkedListNode* insertBiggerNext = xNode->next;
			LinkedListNode* prev = saveHead;
			LinkedListNode *curr = saveHead;
			LinkedListNode* next = curr->next;
			while (curr != xNode)
			{
				if (curr->data > x)
				{
					// insert to the right of x
					// Save the  current pointers
					LinkedListNode *tmp = xNode->next;
					curr->next = tmp;
					xNode->next = curr;
					xNode = tmp;


					prev->next = next;
					next = next->next;

					// reset curr
					curr = prev->next;
				}
				else
				{
					next = curr->next->next;
					prev = curr;
					curr = curr->next;
				}
			}
			// Now curr is xNode
			// Check if items are smaller than xNode
			// You'd have to have saved prev of xNode
			// and keep updating prev of xNode. This is where you will insert nodes < xNode
			LinkedListNode* insertsmaller = prev;
			while (curr != NULL && curr->next != NULL)
			{
				if (curr->data < x)
				{
					prev->next = curr->next;
					curr->next = insertsmaller->next;
					insertsmaller = curr;

					curr = next;
					next = curr->next;
				}
				else
				{
					next = curr->next->next;
					prev = curr;
					curr = curr->next;
				}
			}
		}
		else
		{
			//Account for the case where there is no node with x
			cout << "\n Could not find x. Reached end of list. Quitting. " << endl;
			return;

		}

	}
}*/

void insertAtListEnd(LinkedListNode** head, LinkedListNode** tail, int data)
{
	LinkedListNode* tmp = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	tmp->data = data;
	if (*head == NULL)
	{
		*head = tmp;
		*tail = tmp;
		tmp->next = NULL;
	}
	else
	{
		(*tail)->next = tmp;
		tmp->next = NULL;
		*tail = (*tail)->next;
	}
}

void insertAtListFront(LinkedListNode** head, LinkedListNode** tail, int data)
{
	LinkedListNode* tmp = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	tmp->data = data;
	if (head == NULL)
	{
		*head = tmp;
		*tail = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *head;
		*head = tmp;
	}
}

void partitionLinkedList(LinkedListNode* head, int x)
{
	LinkedListNode* smallerListHead = NULL;
	LinkedListNode* smallerListTail = NULL;
	LinkedListNode* biggerListHead = NULL;
	LinkedListNode* biggerListTail = NULL;

	LinkedListNode* tmp = head;

	while (tmp != NULL)
	{
		if (tmp->data < x)
		{
			insertAtListEnd(&smallerListHead, &smallerListTail, tmp->data);
		}
		else
		{
			insertAtListFront(&biggerListHead, &biggerListTail, tmp->data);
		}

		tmp = tmp->next;
	}

	// Merge the two lists
	smallerListTail->next = biggerListHead;

	head = smallerListHead;

	cout << "\n`Printing the linked list after partition" << endl;
	while (head != NULL)
	{
		cout << head->data << "->";
		head = head->next;
	}
 }

void removeDuplicateNodes(LinkedListNode* &head)
{
	unordered_set<int> nodeData;
	LinkedListNode* prev = head;
	LinkedListNode* cur = head;
	while (cur != NULL)
	{
		// Check if node is in unordered set
		if (nodeData.find(cur->data) != nodeData.end())
		{
			// found duplicate node, delete node from list
			LinkedListNode tmp = *head;
			prev->next = cur->next;
			tmp.next = NULL; // will this be deleted?
		}
		else
		{
			// Node not found in list, add to hash set
			nodeData.insert(cur->data);
			prev = cur;
		}
		cur = cur->next;
	}

	cur = head;
	cout << "\nList without duplicate nodes: " << endl;
	while (cur != NULL)
	{
		cout << cur->data << "->";
		cur = cur->next;
	}
}