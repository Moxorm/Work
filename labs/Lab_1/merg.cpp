#include <stdio.h>
#include <cstdlib>
#include <stdint.h>

int main(void)
{
	void tester();
	tester();
	return 0;
}


void tester()
{
	int merge_sort(uint32_t *array_us, uint32_t len, uint32_t center);
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
	printf("test6 %i\n", test(test6, 0,0));

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

bool test(uint32_t *array_us, uint32_t len, bool pr=1)
{
	int merge_sort(uint32_t *array_us, uint32_t len, uint32_t center);
	void print(uint32_t *array_us, uint32_t len);
	merge_sort(array_us, len, len / 2);
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

int merge_sort(uint32_t *array_us, uint32_t len, uint32_t center)
{
	if (len <= 1)
		return 0;
	merge_sort(array_us, center, center/2);
	merge_sort(&array_us[center], len-center, (len - center)/2);

	uint32_t *array_ = new uint32_t[len];
	uint32_t left = 0, right = 0, ar=0;
	while (left < center)
	{
		if (array_us[left] < array_us[center + right])
		{
			array_[ar] = array_us[left];
			left++;
			ar++;
		}
		else
		{
			array_[ar] = array_us[center + right];
			right++;
			ar++;
			if (center + right == len)
			{
				for (uint32_t i = left; i < center; i++)
				{
					array_[ar] = array_us[i];
					ar++;
				}
				left = center;
			}
		}

	}
	for (uint32_t i = center + right; i < len; i++)
		array_[i]= array_us[i];
	for (uint32_t i = 0; i < len; i++)
		array_us[i] = array_[i];

	delete[] array_;
	return 0;
}