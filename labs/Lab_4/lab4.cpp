#include <iostream>
#include <vector>

struct listones
{
	listones *ch;
	int data;
	listones(int a)
	{
		ch = NULL;
		data = a;
	}
};

class stack_ar
{
	std::vector<int> arr;
public:
	stack_ar(int a)
	{
		arr.push_back(a);
	}
	void push(int a)
	{
		arr.push_back(a);
	}
	int pop()
	{
		if (arr.size() == 0)
			return NULL;
		int a = arr[arr.size() - 1];
		arr.erase(arr.end() - 1);
		return a;
	}
};
class stack_list
{
	listones *end;
public:
	stack_list(int a)
	{
		end = new listones(a);
	}
	void push(int a)
	{
		listones *lis = end;
		end = new listones(a);
		end->ch = lis;
	}
	int pop()
	{
		if (end == NULL)
			return NULL;
		int a = end->data;
		listones *newend = end->ch;
		delete end;
		end = newend;
		return a;
	}

};

class queue_ar
{
	std::vector<int> arr;
public:
	queue_ar(int a)
	{
		arr.push_back(a);
	}
	void push(int a)
	{
		arr.push_back(a);
	}
	int pop()
	{
		if (arr.size() == 0)
			return NULL;
		int a = arr[0];
		arr.erase(arr.begin());
		return a;
	}
};
class queue_list
{
	listones *first;
	listones *last;
public:
	queue_list(int a)
	{
		first = new listones(a);
		last = first;
	}
	void push(int a)
	{
		last->ch = new listones(a);
		last = last->ch;
	}
	int pop()
	{
		if (first == NULL)
			return NULL;
		int a = first->data;
		listones *newfirst = first->ch;
		delete first;
		first = newfirst;
		return a;
	}
};

template<class cal>
void test (cal *st1, int *A)
{
	for (int i = 0; i < 10; i++)
		st1->push(A[i]);
	for (int i = 0; i <11; i++)
		printf("%i ", st1->pop());
	printf("\n");
}

int main(void)
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	test(&stack_ar(0),a);
	test(&stack_list(0),a);
	test(&queue_ar(0),a);
	test(&queue_list(0),a);


	return 0;
}

