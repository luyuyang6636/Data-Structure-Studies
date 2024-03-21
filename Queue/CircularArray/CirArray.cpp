#include <iostream>
using namespace std;

#define N 10

int	A[N];
int	Front = -1;
int	Rear = -1;


bool	IsEmpty()
{
	if (Front == -1 && Rear == -1)
		return (true);
	return (false);
}

bool	IsFull()
{
	if ((Rear + 1) % N == Front)
	{
		cout << "Queue is full!" << endl;
		return (true);
	}
	return (false);
}

void	EnQueue(int x)
{
	if (IsFull())
		return;
	else if (IsEmpty())
		Front = Rear = 0;
	else
		Rear = (Rear + 1) % N;
	A[Rear] = x;
}

void	DeQueue(void)
{
	if (IsEmpty())
	{
		cout << "The queue is empty!" << endl;
		return;
	}
	if (Front == Rear)
		Front = Rear = -1;
	else
		Front = (Front + 1) % N;
}

void	Print()
{
	int	i = Front - 1;
	if (IsEmpty())
	{
		cout << "The queue is empty!" << endl;
		return;
	}
	while ((i + 1) % N != Rear)
	{
		cout << A[(i + 1) % N] << ", " << flush;
		i++;
	}
	cout << A[Rear] << ", " << flush;
	cout << endl;
}

int	main(void)
{
	for (int i = 0; i < N; i++)
	{
		EnQueue(i);
	}
	Print();
	EnQueue(7);
	DeQueue();
	EnQueue(7);
	Print();
	for (int i = 0; i <= N; i++)
		DeQueue();
	Print();
}
		
