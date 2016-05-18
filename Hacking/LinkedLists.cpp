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

	for (unsigned int i = 0; i < 5; i++)
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
	cout << "Printing the linked list in reverse" << endl;
	while (tmpNode != NULL)
	{
		cout << tmpNode->data << "->";
		tmpNode = tmpNode->next;
	}

	// However, we cheated here a bit. We assumed the list was not created and created one inserting the new 
	// nodes in the front.
	// To do this the right way, assume the list is given to you and you need to reverse it using pointer manipulation.
	reverseLinkedListReal(head);

	return;
}

LinkedListNode* reverseLinkedListReal(LinkedListNode* head)
{

}