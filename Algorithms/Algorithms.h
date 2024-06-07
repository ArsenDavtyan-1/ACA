#ifndef ALGORITMS_H_
#define ALGORITMS_H_

template <typename T>
void BubbleSort(T array[], const int size)
{
	for (int i = 1; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				T temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}





template <typename T>
void Merge(T array[], int p, int q, int r)
{
	int size1 = q - p + 1;
	int size2 = r - q;
	T* left = new T[size1];
	T* right = new T[size2];

	for (int i = 0; i < size1; ++i)
		left[i] = array[p + i];
	for (int i = 0; i < size2; ++i)
		right[i] = array[q + i + 1];

	int i = 0;
	int j = 0;
	int k = p;
	while (i < size1 && j < size2)
	{
		if (left[i] < right[j])
		{
			array[k] = left[i];
			++i;
		}
		else
		{
			array[k] = right[j];
			++j;
		}
		++k;
	}

	while (i < size1)
	{
		array[k] = left[i];
		++i;
		++k;
	}
	while (j < size2)
	{
		array[k] = right[j];
		++j;
		++k;
	}

	delete[] left;
	delete[] right;
}


template <typename T>
void MergeSort(T array[], int p, int r)
{
	if (p >= r)
		return;
	int q = (p + r) / 2;
	MergeSort(array, p, q);
	MergeSort(array, q + 1, r);
	Merge(array, p, q, r);
}




#endif // !ALGORITMS_H_
