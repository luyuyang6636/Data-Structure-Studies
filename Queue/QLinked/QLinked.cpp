#include <iostream>
using namespace std;
#define N 10

struct s_list
{
	int		data;
	struct s_list	*next;
};

s_list	*Front = NULL;
s_list	*Rear = NULL;

s_list	*newNode(int x)
{
	s_list	*node = new s_list();

	node->data = x;
	node->next = NULL;
	return (node);
}

bool	IsEmpty()
{
	if (Rear == NULL && Front == NULL)
		return (true);
	return (false);
}

void	EnQueue(int x)
{
	s_list	*tmp = newNode(x);

	if (IsEmpty())
	{
		Front = Rear = tmp;
		return;
	}
	Rear->next = tmp;
	Rear = tmp;
}

void	DeQueue(void)
{
	s_list	*tmp = Front;

	if (IsEmpty())
	{
		cout << "The queue is empty, cannot dequeue!" << endl;
		return;
	}
	if (Front == Rear)
		Front = Rear = NULL;
	else
		Front = Front -> next;
	delete tmp;
}

void	Print()
{
	s_list	*tmp = Front;

	if (IsEmpty())
	{
		cout << "The queue is empty, cannot print!" << endl;
		return;
	}
	while (tmp != Rear)
	{
		cout << tmp->data << ", " << flush;
		tmp = tmp->next;
	}
		cout << Rear->data << endl;
}

int	main(void)
{
	for (int i = 0; i < N; i++)
	{
		EnQueue(i);
	}
	Print();
	for (int i = 0; i <= N; i++)
		DeQueue();
	Print();
}
