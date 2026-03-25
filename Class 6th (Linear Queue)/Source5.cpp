#include <iostream>

using namespace std;

#define SIZE 5

template <typename T>

class Queue
{
private:
	int front;
	int rear;

	T container[SIZE];
public:
	Queue()
	{
		rear = 0;
		front = 0;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		if (rear >= SIZE)
		{
			cout << "linear queue overflow" << endl;
		}
		else
		{
			container[rear++] = data;
		}
	}

	const bool& empty()
	{
		return front == rear;
	}

	void pop()
	{
		if (empty())
		{
			cout << "linear queue is empty" << endl;
		}
		else
		{
			container[front++] = NULL;
		}
	}

	const T& peek()
	{
		return container[front];
	}

	const int& size()
	{
		return rear - front;
	}
};

int main()
{
	Queue<int> queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);
	queue.push(40);
	queue.push(50);

	while (queue.empty() == false)
	{
		cout << queue.peek() << endl;

		queue.pop();
	}

	cout << "Queue Size : " << queue.size() << endl;


	queue.push(60);

	return 0;
}
