#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

uint32_t main(uint32_t argc, char *argv[])
{
	void quick_sort(uint32_t N);
	uint32_t N = 1000;
	quick_sort(N);

	return 0;
}

void quick_sort(uint32_t N)
{
	uint32_t *Arr = (uint32_t*)malloc(N * sizeof(uint32_t));
	for (int32_t i = 0; i<N; i++)
	{
		Arr[i] = rand() % 1000;
		cout << Arr[i] << " ";
	}
	cout << endl;

	void quic(uint32_t * q, uint32_t l);
	quic(Arr, N);

	for (int32_t i = 0; i<N; i++)
		cout << Arr[i] << " ";
	cout << endl;

	free(Arr);
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
		for (uint32_t j = 0; j < 3 - i-1 ; j++) 
		{
			if (A[j] > A[j + 1]) 
			{
				uint32_t tmp = A[j];
				A[j] = A[j+1];
				A[j+1] = tmp;
			}
		}
	}
	return A[1];
}

void quic(uint32_t * arr, uint32_t len)
{
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
			quic(arr + j, len - j);
			len = j + 1;
		}
		else
		{
			quic(arr, j + 1);
			arr = arr + i;
			len = len - i;
		}
	}
}

