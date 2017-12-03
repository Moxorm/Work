#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <string>

class elem
{
	friend class prqueue;
	uint32_t key;
	std::string value;
	elem(std::string val, uint32_t ke)
	{
		key = ke;
		value = val;
	}
public:
	~elem() {};
};

class prqueue
{
	std::vector<elem> vec;
	uint32_t len;
public:
	prqueue(std::string val, uint32_t ke)
	{
		elem *el = new elem(val, ke);
		vec.push_back(*el);
		len=1;
	}
	void insert(std::string val, uint32_t ke);
	std::string maximum();
	void extractmax();
	void print();
	~prqueue() {};
};




void prqueue::insert(std::string val, uint32_t ke)
{
	elem *el = new elem(val, ke);
	this->vec.push_back(*el);
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
	while(k*2+2<this->len&&(this->vec[k].key < this->vec[k *2+1].key|| this->vec[k].key < this->vec[k * 2 + 2].key))
	{
		if (this->vec[k*2+2].key < this->vec[k * 2 + 1].key)
		{
			std::swap(this->vec[k], this->vec[k * 2 + 1]);
			k = k * 2 + 1;
		}
		else
		{
			std::swap(this->vec[k], this->vec[k * 2 + 2]);
			k = k * 2 + 2;
		}

	}
	if (k * 2 + 1<this->len&&this->vec[k].key < this->vec[k * 2 + 1].key)
		std::swap(this->vec[k], this->vec[k * 2 + 1]);
}




int main(void)
{
	prqueue que("kdfkk", 34);
	que.insert("kkk", 11);
	que.insert("ttt", 13);
	que.insert("qqq", 1);
	que.insert("eee", 4);
	que.insert("www", 3);
	que.insert("rrr", 7);
	que.insert("uuu", 6);
	que.insert("ooo", 20);

	que.print();
	que.extractmax();
	std::cout << std::endl;
	que.print();
	std::cout << std::endl;

	std::cout << que.maximum() << std::endl;

	return 0;
}