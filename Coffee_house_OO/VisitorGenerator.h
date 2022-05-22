#pragma once
#include "Visitor.h"
#include <list>

class VisitorGenerator
{
public:
	VisitorGenerator() {}

	void addVisitor(int number_of, int menu_size) {
		for (int i = 0; i < number_of; ++i) {
			srand(time(NULL));
			queue.push_back(rand() % 3 + menu_size);
		}
	}

	void deQueueVisitor(int number_of) {
		for (int i = 0; i < number_of; ++i) {
			queue.pop_front();
		}
	}

	std::list<int> getQueue()
	{
		return queue;
	}

private:
	std::list<int> queue;
};