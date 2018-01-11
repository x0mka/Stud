#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <string>

using namespace std;

class Queue
{
	public:
		Queue();
		~Queue();	
		int length;
		void Insert();
		void ExtractMax();
		string Maximum();
	private:
		string *value;
		unsigned int *key;
		

};

#endif // QUEUE_H
