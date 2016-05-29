#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

using namespace std;

void createBST(TreeNode* &node);
void insertNode(TreeNode* &node, int data);
unsigned getHeight(TreeNode* &node);
void LevelOrderTraversal(TreeNode* &node);

void LevelOrderTraversal(TreeNode* &node)
{
	queue<TreeNode*> nodeQ;
	if (node == NULL)
	{
		return;
	}
	else
	{
		nodeQ.push(node);
		while (!nodeQ.empty())
		{
			TreeNode* tmp = nodeQ.front();
			
			// Process node
			cout << " " << tmp->data;

			// Queue node's children
			if (tmp->left != NULL)
			{
				nodeQ.push(tmp->left);
			}
			if(tmp->right != NULL)
			{
				nodeQ.push(tmp->right);
			}
			nodeQ.pop();

		}
	}
}

void insertNode(TreeNode* &node, int data)
{
	if (node == NULL)
	{
	    node = (TreeNode*)malloc(sizeof(TreeNode));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	else
	{
		if (data <= node->data)
		{
			insertNode(node->left, data);
		}
		else
		{
			insertNode(node->right, data);
		}
	}
}

unsigned getHeight(TreeNode* &root)
{
	if (root == NULL )
	{
		return 0;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		return 0;
	}
	else
	{
		unsigned height = 1 + max(getHeight(root->left), getHeight(root->right));
		return height;
	}
}

void createBST(TreeNode* &root)
{
	int numNodes = 0;
	int inpCount = 0;
	int data = 0;
	int height = 0;
	cout << "\nEnter number of nodes in your tree: ";
	cin >> numNodes;

	cout << "\nEnter " << numNodes << ":";
	
	while (inpCount < numNodes)
	{
		cin >> data;

		insertNode(root, data);
		inpCount++;
	}
	
}

void main_Tree()
{
	TreeNode* node = NULL;
	createBST(node);
	cout<< "Height of tree is: " << getHeight(node) <<endl;
	LevelOrderTraversal(node);

}
