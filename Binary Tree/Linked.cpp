#include <iostream>
#include <queue>
using namespace std;

struct	Node{
	int	data;
	Node	*left;
	Node	*right;
};

Node	*newNode(int x)
{
	Node	*tmp = new Node();

	tmp->data = x;
	tmp->left = NULL;
	tmp->right = NULL;
	return (tmp);
}

Node	*Insert(Node *root, int x)
{
	if (root == NULL)
		root = newNode(x);
	else if (x <= root->data)
		root->left = Insert(root->left, x);
	else if (x > root->data)
		root->right = Insert(root->right, x);
	return (root);
}


bool	Search(Node *root, int x)
{
	if (root == NULL)
		return (false);
	else if (root->data == x)
		return (true);
	else if (x <= root->data)
		return (Search(root->left, x));
	else
		return (Search(root->right, x)); 
}

int	FindMin(Node *root)
{
	Node	*tmp = root;

	if (!tmp)
	{
		cout << "The tree is empty!" << endl;
		return (-1);
	}
	while (tmp->left)
		tmp = tmp->left;
	return(tmp->data);
}

int	FindHeight(Node *root)
{
	if (root == NULL)
		return (-1);
	return (max(FindHeight(root->left), FindHeight(root->right)) + 1);
}

int	FindMax(Node *root)
{
	Node	*tmp = root;

	if (!tmp)
	{
		cout << "The tree is empty!" << endl;
		return (-1);
	}
	while (tmp->right)
		tmp = tmp->right;
	return (tmp->data);
}

void	Preorder(Node *root) //Space: best/avg O(log2 n), worst O(n) Time: O(n) - one function call each node
{
	if (!root)
	{
		cout << "Empty tree!" << endl;
		return;
	}
	cout << root->data << ", " << flush;
	if (root->left)
		Preorder(root->left);
	if (root->right)
		Preorder(root->right);
}

void	Inorder(Node *root)
{
	if (!root)
	{
		cout << "Empty tree!" << endl;
		return;
	}
	if (root->left)
		Inorder(root->left);
	cout << root->data << ", " << flush;
	if (root->right)
		Inorder(root->right);
}

void	Postorder(Node *root)
{
	if (!root)
	{
		cout << "Empty tree!" << endl;
		return;
	}
	if (root->left)
		Postorder(root->left);
	if (root->right)
		Postorder(root->right);
	cout << root->data << ", " << flush;
}

void	LevelOrder(Node *root) //Time: O(n), Space: best O(1) when just a linked list, worst/avg O(n)
{
	queue<Node *>	Q;

	if (root == NULL)
		return;
	Q.push(root);
	while (!Q.empty())
	{
		Node	*cur = Q.front();
		cout << cur->data << ", " << flush;
		if (cur->left)
			Q.push(cur->left);
		if (cur->right)
			Q.push(cur->right);
		Q.pop();
	}
}

int	main(void)
{
	Node	*root = NULL;

	root = Insert (root, 15);
	root = Insert (root, 10);
	root = Insert (root, 30);
	root = Insert (root, 20);
	root = Insert (root, 7);
	root = Insert (root, 50);
	root = Insert (root, 5);
	root = Insert(root, 12);

	Preorder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	Postorder(root);
	cout << endl;
	LevelOrder(root);
	cout << endl;
//	cout << Search(root, 19) << endl;
}

