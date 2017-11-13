#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <string>

class elem
{
public:
	uint32_t key;
	std::string value;
	elem(std::string val, uint32_t ke)
	{
		key = ke;
		value = val;
	}
	~elem() {};
};

class prqueue
{
	std::vector<elem> vec;
	uint32_t len;
public:
	prqueue(elem el)
	{
		vec.push_back(el);
		len=1;
	}
	void insert(elem el);
	std::string maximum();
	void extractmax();
	void print();
	~prqueue() {};
};




void prqueue::insert(elem el)
{
	this->vec.push_back(el);
	uint32_t k = this->len;

	while (this->vec[k].key > this->vec[k / 2].key)
	{
		std::swap(this->vec[k], this->vec[k/2]);
		k = k / 2;
	}
	this->len++;
}
void prqueue::print()
{
	for (uint32_t i = 0; i < this->len; i++)
	{
		printf("%i ", this->vec[i].key);
	}
}
std::string prqueue::maximum()
{
	return this->vec[0].value;
}
void prqueue::extractmax()
{
	std::swap(this->vec[0], this->vec[this->len-1]);
	this->vec.erase(this->vec.end() - 1);
	this->len--;
	uint32_t k = 0;
	while(k*2+2<this->len)
	{
		if (this->vec[k*2+2].key < this->vec[k * 2 + 1].key)
		{
			std::swap(this->vec[k], this->vec[k * 2 + 1]);
			k = k * 2 + 1;
		}
		else
		{
			std::swap(this->vec[k], this->vec[k * 2 + 2]);
			k = k * 2 + 1;
		}

	}
	if (k * 2 + 1<this->len)
		std::swap(this->vec[k], this->vec[k * 2 + 1]);
}




int main(void)
{
	elem el1("fff", 12);
	elem el2("kkk", 11);
	elem el3("ttt", 13);
	elem el4("qqq", 1);
	elem el5("eee", 4);
	elem el6("www", 3);
	elem el7("rrr", 7);
	elem el8("uuu", 6);
	elem el9("ooo", 20);


	prqueue que(el1);
	que.insert(el2);
	que.insert(el3);
	que.insert(el4);
	que.insert(el5);
	que.insert(el6);
	que.insert(el7);
	que.insert(el8);
	que.insert(el9);

	que.print();
	que.extractmax();
	std::cout << std::endl;
	que.print();
	std::cout << std::endl;

	std::cout << que.maximum() << std::endl;

	return 0;
}