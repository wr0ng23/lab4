#pragma once
template <typename T>
void SelectionSort(T* mass, size_t size, char flag = 'u')
{
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t minPosition = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (flag == 'u')
			{
				if (mass[minPosition] > mass[j])
					minPosition = j;
			}
			else
				if (mass[minPosition] < mass[j])
					minPosition = j;
		}

		if (mass[minPosition] != mass[i])
		{
			T tmp = mass[minPosition];
			mass[minPosition] = mass[i];
			mass[i] = tmp;
		}
	}
}

template <>
void SelectionSort(char** mass, size_t size, char flag)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t minPosition = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (flag == 'u')
			{
				if (strcmp(mass[minPosition], mass[j]) > 0)
					minPosition = j;
			}
			else
				if (strcmp(mass[minPosition], mass[j]) < 0)
					minPosition = j;
		}

		if (mass[minPosition] != mass[i])
		{
			char* tmp = mass[minPosition];
			mass[minPosition] = mass[i];
			mass[i] = tmp;
		}
	}
}