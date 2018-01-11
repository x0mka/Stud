#include <iostream>

using namespace std;

int const length = 10;

void mergeSort(int *, int, int);

void main()
{
	int *mas = new int[length];
	for (int counter = 0; counter < length; counter++)
	{
		mas[counter] = (rand() % 100);
		cout << mas[counter] << " ";
	}
	cout << endl;
	mergeSort(mas, 0, length-1);
	for (int counter = 0; counter < length; counter++)
		cout << mas[counter] << " ";
	cout << endl;
	delete[] mas;
}

void mergeSort(int *mas, int leftBorder, int rightBorder)
{
	if (leftBorder == rightBorder)
		return;
	int middle = (int)(leftBorder + rightBorder)*0.5;
	mergeSort(mas, leftBorder, middle);
	mergeSort(mas, middle + 1, rightBorder);
	int leftCurent = leftBorder;
	int rightCurent = middle + 1;
	int *result = new int[rightBorder+1];
	for (int counter = 0; counter < rightBorder - leftBorder + 1; counter++)
	{
		if ((rightCurent > rightBorder) || (leftCurent <= middle) && (mas[leftCurent]<mas[rightCurent]))
		{
			result[counter] = mas[leftCurent];
			leftCurent++;
		}
		else
		{
			result[counter] = mas[rightCurent];
			rightCurent++;
		}
	}
	for (int counter = 0; counter < rightBorder - leftBorder + 1; counter++)
		mas[leftBorder + counter] = result[counter];
	delete[] result;
}
