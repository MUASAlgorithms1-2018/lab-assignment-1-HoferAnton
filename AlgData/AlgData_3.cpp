// AlgData_3.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

class Stack {
private:
	char* internal;
	int stack_size;
	int current;

public:
	Stack(int n) {
		internal = new char[n];
		stack_size = n;
		current = -1;
	}

	int size() {
		return current;
	}

	void push(char c) {
		if (current + 1 == stack_size)
		{
			throw "StackFullException";
		}
		current = current++;
		internal[current] = c;
	}

	char pop() {
		if (current == -1)
		{
			throw "StackFullException";
		}
		char a = internal[current];
		internal[current] = 0;
		current--;
		return a;
	}
};

int proj_3_main()
{
	Stack a = Stack(3);
	a.push('(');
	a.push('(');
	a.push('(');
	std::cout << " return: " << a.pop();
	std::cout << " return: " << a.pop();
	std::cout << " return: " << a.pop();
	return 0;
}