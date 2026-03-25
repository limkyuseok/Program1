#include <iostream>

using namespace std;

#define SIZE 4

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
		front = SIZE - 1;
		rear = SIZE - 1;

		for (int i = 0; i < SIZE; i++)
		{
			container[i] = NULL;
		}
	}

	void push(T data)
	{
		if (front == (rear + 1) % SIZE)
		{
			cout << "Circle Queue overflow" << endl;
		}
		else
		{
			rear = (rear + 1) % SIZE;

			container[rear] = data;
		}
	}

	void pop()
	{
		if (empty())
		{
			cout << "circle queue is empty" << endl;
		}
		else
		{
			front = (front + 1) % SIZE;

			container[front] = NULL;
		}
	}

	const bool& empty()
	{
		return front == rear;
	}

	const T& peek()
	{
		return container[(front + 1) & SIZE];
	}
};

int main()
{
	Queue<int> queue;

	queue.push(10);
	queue.push(20);
	queue.push(30);

	while (queue.empty() == false)
	{
		cout << queue.peek() << endl;

		queue.pop();
	}

	queue.push(40);

	return 0;
}
