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
	stack_ar()
	{
	
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
	bool check;
public:
	stack_list()
	{
		check=0;
		end = NULL;
	}
	void push(int a)
	{
		if (!check)
		{
			check = 1;
			end = new listones(a);
		}
		else
		{
			listones *lis = end;
			end = new listones(a);
			end->ch = lis;
		}
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
	queue_ar()
	{
		
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
	bool check;
public:
	queue_list()
	{
		check = 0;
		first = NULL;
		last = NULL;
	}
	void push(int a)
	{
		if (!check)
		{
			check = 1;
			first= new listones(a);
			last= first;
		}
		else
		{
			last->ch = new listones(a);
			last = last->ch;
		}
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
void test(cal *st1, int *A)
{
	printf("%i ", st1->pop());
	for (int i = 0; i < 10; i++)
		st1->push(A[i]);
	for (int i = 0; i < 12; i++)
		printf("%i ", st1->pop());
	printf("\n");
}

void tester()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	queue_list ql;
	queue_ar qa;
	stack_list sl;
	stack_ar sa;

	test(&sa, a);
	test(&sl, a);
	test(&qa, a);
	test(&ql, a);
}

int main(void)
{
	tester();


	return 0;
}

