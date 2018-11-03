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
		return current+1;
	}

	void push(char c) {
		if (current + 1 == stack_size)
		{
			throw "StackFullException";
		}
		current = current+1;
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

bool parenthesis(std::string input, int size) {
	Stack a = Stack(size);
	if ((size % 2) == 1) {
		return false;
	}
	for (int string_pos = 0; string_pos < size; string_pos++) {
		if (input[string_pos] == '(') {
			a.push('a');
		}
		else{
			if (a.size() > 0) {
				a.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return a.size() == 0;

}

int main()
{
	std::string par = std::string(")");

	if (parenthesis(par, par.size()) == 1) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;

	}

	return 0;
}