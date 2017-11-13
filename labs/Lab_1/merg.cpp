#include <stdio.h>
#include <cstdlib>
#include <stdint.h>

int main(void)
{
	void merge(uint32_t N);
	uint32_t N = 100;
	merge(N);
	return 0;
}

void merge(uint32_t N)
{
	uint32_t *array_main = new uint32_t[N];
	for (uint32_t i = 0; i < N; i++)
	{
		array_main[i] = 100 - rand() % 100;
		printf("%i ", array_main[i]);
	}
	int merge_sort(uint32_t *array_us, uint32_t len, uint32_t center);
	merge_sort(array_main, N, N / 2);

	printf("\n");

	for (uint32_t i = 0; i < N; i++)
		printf("%i ", array_main[i]);
	delete[] array_main;
}

int merge_sort(uint32_t *array_us, uint32_t len, uint32_t center)
{
	if (len == 1)
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