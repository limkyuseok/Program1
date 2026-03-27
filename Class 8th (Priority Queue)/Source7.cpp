#include <iostream>

using namespace std;

template <typename T>

class PriorityQueue
{
private:
	int capacity;
	int index;

	T* container;
public:
	PriorityQueue()
	{
		capacity = 0;
		index = 0;
		container = nullptr;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* temporary = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		for (int i = 0; i < index; i++)
		{
			temporary[i] = container[i];
		}

		delete[] container;

		container = temporary;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (index >= capacity)
		{
			resize(capacity * 2);
		}

		container[index++] = data;

		int child = index - 1;
		int parent = (child - 1) / 2;

		while (child > 0)
		{
			if (container[parent] < container[child])
			{
				std::swap(container[parent], container[child]);
			}

			child = parent;

			parent = (child - 1) / 2;
		}
	}

	void pop()
	{
		if (index <= 0)
		{
			cout << "Pirority queue is empty" << endl;
		}
		else
		{
			container[0] = container[--index];

			container[index] = NULL;

			int parent = 0;
			int child = parent * 2 + 1;

			while (child < index)
			{
				child = parent * 2 + 1;

				if (container[child] < container[child + 1])
				{
					child++;
				}

				if (container[child] < container[parent])
				{
					break;
				}
				else
				{
					std::swap(container[child], container[parent]);

					parent = child;
				}
			}
		}
	}

	const bool& empty()
	{
		return index <= 0;
	}

	/*const int & size()
	{
		return size;
	}*/

	const T& top()
	{
		return container[0];
	}

	~PriorityQueue()
	{
		delete[] container;
	}
};

int main()
{
	PriorityQueue<int> priorityqueue;

	priorityqueue.push(20);
	priorityqueue.push(10);
	priorityqueue.push(15);
	priorityqueue.push(30);
	priorityqueue.push(40);

	while (priorityqueue.empty() == false)
	{
		cout << priorityqueue.top() << endl;

		priorityqueue.pop();
	}

	//cout << "Priority Queue is Size : " << priorityqueue.size() << endl;

	return 0;
}
