// Custom implementation of vector (dynamic array)
#include <iostream>

using namespace std;

class Vect
{
private:
	int size_v;
	int capacity_v;
	int *array;

public:
	Vect(int length = 1)
	{
		size_v = 0;
		int size_alloc = 16;
		while (size_alloc < length)
		{
			size_alloc *= 2;
		}
		capacity_v = size_alloc;
		array = new int[capacity_v];
	}

	int size()
	{
		return size_v;
	}

	int capacity()
	{
		return capacity_v;
	}

	bool is_empty()
	{
		return size_v == 0;
	}

	int at(int index)
	{
		if (index >= capacity_v)
		{
			cout << "Out out bounds\n";
			return -1;
		}
		else
		{
			return *(array + index);
		}
	}

	void push(int item)
	{
		if (size_v == capacity_v)
		{
			resize(2 * capacity_v);
		}

		*(array + size_v) = item;
		size_v++;
	}

	void insert(int index, int item)
	{
		if (size_v + 1 >= capacity_v)
		{
			resize(2 * capacity_v);
		}
		for (int i = size_v - 1; i >= index; i--)
		{
			*(array + i + 1) = *(array + i);
		}

		*(array + index) = item;
	}

	void prepend(int item)
	{
		insert(0, item);
	}

	int pop()
	{
		int val = *(array + size_v - 1);
		size_v--;
		if (size_v * 4 == capacity_v)
		{
			resize(capacity_v / 2);
		}
		return val;
	}

	void delete_item(int index)
	{
		for (int i = index; i < size_v; i++)
		{
			*(array + i) = *(array + i + 1);
		}
	}

	void remove(int item)
	{
		for (int i = 0; i < size_v; i++)
		{
			if (*(array + i) == item)
			{
				delete_item(i);
			}
		}
	}

	int find(int item)
	{
		for (int i = 0; i < size_v; i++)
		{
			if (*(array + i) == item)
			{
				return i;
			}
		}

		return -1;
	}

	void resize(int new_capacity)
	{
		int a = new_capacity < capacity_v ? new_capacity : capacity_v;
		int *temp = new int[new_capacity];
		for (int i = 0; i < a; i++)
		{
			*(temp + i) = *(array + i);
		}
		delete array;
		array = temp;
		capacity_v = new_capacity;
	}
};

int main()
{
	Vect v(20);
	for (int i = 0; i < 33; i++)
	{
		v.push(i + 1);
	}
	for (int i = 0; i < 33; i++)
	{
		cout << v.at(i) << '\n';
	}
	cout << v.capacity() << '\n';
}