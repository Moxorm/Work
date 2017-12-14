#include <string>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdint.h>


int main()
{
	void tester();
	tester();

	return 0;
}


void tester()
{
	bool test(uint32_t *array_us, uint32_t len, bool pr = 1);

	uint32_t test1[10] = { 3,7,4,6,10,2,5,1,9,8 };
	printf("test1 %i\n", test(test1, 10));

	uint32_t test2[1] = { 8 };
	printf("test2 %i\n", test(test2, 1));

	uint32_t test3[2] = { 7,3 };
	printf("test3 %i\n", test(test3, 2));

	uint32_t test4[3] = { 5,7,4 };
	printf("test4 %i\n", test(test4, 3));

	uint32_t test5[10] = { 1,1,1,1,1,1,1,1,1,1 };
	printf("test5 %i\n", test(test5, 10));

	uint32_t *test6 = (uint32_t*)malloc(0);
	printf("test6 %i\n", test(test6, 0, 0));

	uint32_t test7[10000];
	for (uint32_t i = 0; i < 10000; i++)
	{
		test7[i] = rand() % 10000;
	}
	printf("test7 %i\n", test(test7, 10000, 0));

	uint32_t test8[10000];
	for (uint32_t i = 0; i < 10000; i++)
	{
		test8[i] = 10000 - i;
	}
	printf("test8 %i\n", test(test8, 10000, 0));
	free(test6);
}

bool test(uint32_t *array_us, uint32_t len, bool pr = 1)
{
	void quick_sort(uint32_t *Arr, uint32_t N);
	void print(uint32_t *array_us, uint32_t len);
	quick_sort(array_us, len);
	if (pr)
	{
		print(array_us, len);
		printf("\n");
	}



	for (uint32_t i = 1; i < len; i++)
	{
		if (array_us[i] < array_us[i - 1])
			return false;
	}
	return true;
}

void print(uint32_t *array_us, uint32_t len)
{
	for (uint32_t i = 0; i < len; i++)
		printf("%i ", array_us[i]);
}


void quick_sort(uint32_t *arr, uint32_t len)
{
	int gen(uint32_t *q, uint32_t l);
	while (len>1)
	{
		uint32_t j = len - 1, i = 0;
		uint32_t s = gen(arr, len);
		while (i <= j)
		{
			while (arr[i]<s)
				i++;
			while (arr[j]>s)
				j--;
			if (i <= j)
			{
				uint32_t lel = arr[i];
				arr[i] = arr[j];
				arr[j] = lel;
				i++;
				j--;
			}
		}
		if ((j + 1) > (len - j))
		{
			quick_sort(arr + j, len - j);
			len = j + 1;
		}
		else
		{
			quick_sort(arr, j + 1);
			arr = arr + i;
			len = len - i;
		}
	}
}

int gen(uint32_t *q, uint32_t l)
{
	if (l < 3)
		return q[1];
	uint32_t A[3];
	srand(time(NULL));
	A[0] = q[rand() % l];
	srand(time(NULL));
	A[1] = q[rand() % l];
	srand(time(NULL));
	A[2] = q[rand() % l];
	for (uint32_t i = 0; i < 3; i++)
	{
		for (uint32_t j = 0; j < 3 - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				uint32_t tmp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = tmp;
			}
		}
	}
	return A[1];
}



