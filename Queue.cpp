#include <iostream>
#include "Queue.h"

Queue::Queue()
{
	length = 0;

};
Queue::~Queue()
{
	
};
void Queue::ExtractMax()
{
	for (int counter = 0; counter < length - 1; counter++)
	{
		value[counter] = value[counter + 1];
		key[counter] = key[counter + 1];
		length--;
	}
};
void Queue::Insert()
{
	int k;
	string str;
	cout << "Введите ключ" << endl;
	cin >> k;
	cout << "Введите строку" << endl;
	cin >> str;
	if (length == 0)
	{
		value[0] = str;
		key[0] = k;
		length++;
	}
	else
	{
		for (int counter = 0; counter < length; counter++)
		{
			if (key[counter] < k)
			{
				for (int i = length; i >= counter; i--)
				{
					value[i+1] = value[i];
					key[i + 1] = key[i];
				}
				value[counter] = str;
				key[counter] = k;
				length++;
			}
		}
	}
};
string Queue::Maximum()
{
	return value[0];
}
