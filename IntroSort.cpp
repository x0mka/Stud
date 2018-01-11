#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

unsigned int const length = 10;
unsigned int const depthLimit = (log(length)+1)*(log(length)+1);

using namespace std;

void quickSort(int *, int, int, int &, int &);
void heapSort(int *);
void introSort(int *mas);
int median(int *, int, int);
void printMas(int *mas);
void swap(int *a, int *b);

void main()
{
	setlocale(LC_ALL, "rus");
	// Создание и заполнение массива случайными числами
	int *mas = new int[length];
	for (int counter = 0; counter < length; counter++)
	{
		//srand(time(NULL)+rand());
		mas[counter] = (rand() % 100);
	}
	cout << "Неотсортированный массив" << endl ;
	printMas(mas);
	cout << endl;
	introSort(mas);
	cout << "Отсортированный массив" << endl;
	printMas(mas);
}

void quickSort(int *mas, int left, int right, int &depth, int &maxDepth)
{
	try
	{
		if (maxDepth > depthLimit)
		{
			throw 1;
		}
	}
	catch (int i)
	{
		//cout << "Ошибка №" << i << "Превышена допустимая глубина рекурсии" << endl;
		return;
	}
	depth++;
	if (depth > maxDepth)
		maxDepth = depth;
	int l = left;
	int r = right;
	int pivot = median(mas, left, right);
	while (l < r)
	{
		while (mas[l] < mas[pivot])
			l++;
		while (mas[r] > mas[pivot])
			r--;
		if (l <= r)
		{
			swap(mas[l], mas[r]);
			l++;
			r--;
		}
		if (l < right)
			quickSort(mas, l, right, depth, maxDepth);
		if (left < r)
			quickSort(mas, left, r, depth, maxDepth);
	}
	depth--;
}

void heapSort(int *mas)
{
	int sh = 0;
	bool flag;
	while (sh + 2 != length)
	{
		flag = 0;
		for (int i = 0; i < length; ++i)
		{
			if (i * 2 + 2 + sh < length)
			{
				if (mas[i + sh] > mas[i * 2 + 1 + sh] || mas[i + sh] > mas[i * 2 + 2 + sh])
				{
					if (mas[i * 2 + 1 + sh] < mas[i * 2 + 2 + sh])
					{
						swap(&mas[i + sh], &mas[i * 2 + 1 + sh]);
						flag = 1;
					}
					else if (mas[i * 2 + 2 + sh] < mas[i * 2 + 1 + sh])
					{
						swap(&mas[i + sh], &mas[i * 2 + 2 + sh]);
						flag = 1;
					}
				}
			}
			else if (i * 2 + 1 + sh < length)
			{
				if (mas[i + sh] > mas[i * 2 + 1 + sh])
				{
					swap(&mas[i + sh], &mas[i * 2 + 1 + sh]);
					flag = 1;
				}
			}
		}
		if (!flag) 
			sh++;
	}
}

void introSort(int *mas)
{
	int maxDepth = 0, depth = 0;
	quickSort(mas, 0, length - 1, depth, maxDepth); 
	cout << "Глубина рекурсии quickSort достигла " << maxDepth << endl;
	cout << endl;
	if (maxDepth > depthLimit)
	{
		cout << "Глубина рекурсии quickSort превысила максимальную. Начинает работать heapSort." << endl;
		heapSort(mas);
	}
	cout << endl;
}

int median(int *mas, int left, int right)
{
	int middle = (int)(right + left)*0.5;
	int pivot;
	if ((mas[left] <= mas[middle] && mas[middle] <= mas[right]) || (mas[right] <= mas[middle] && mas[middle] <= mas[left]))
		pivot = middle;
	if ((mas[left] <= mas[right] && mas[right] <= mas[middle]) || (mas[middle] <= mas[right] && mas[right] <= mas[left]))
		pivot = right;
	if ((mas[middle] <= mas[left] && mas[left] <= mas[right]) || (mas[right] <= mas[left] && mas[left] <= mas[middle]))
		pivot = left;
	return pivot;
}

void printMas(int *mas)
{
	for (int i = 0; i < length; i++)
		cout << mas[i] << " ";
	cout << endl;
}
void swap(int *a, int *b)
{
	int var = *a;
	*a = *b;
	*b = var;
}