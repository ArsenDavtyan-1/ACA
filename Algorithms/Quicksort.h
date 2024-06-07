#ifndef QUICKSORT_H_
#define QUICKSORT_H_



template <typename T>
int partition(T array[], int p, int r)
{
	T x = array[r];
	int i = p - 1;
	for (int j = p; j < r; ++j)
	{
		if (array[j] < x)
		{
			++i;
			T temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	T temp = array[i + 1];
	array[i + 1] = array[r];
	array[r] = temp;
	return i + 1;
}


template <typename T>
void Quicksort(T array[], int p, int r)
{
	int q;
	if (p < r)
	{
		int q = partition(array, p, r);
		Quicksort(array, p, q - 1);
		Quicksort(array, q + 1, r );
	}
}

#endif // !QUICKSORT_H_
