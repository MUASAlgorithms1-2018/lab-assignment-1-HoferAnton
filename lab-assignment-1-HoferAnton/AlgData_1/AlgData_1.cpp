// AlgData_1.cpp : contains main
//

//#include "pch.h" // precompiled header file
#include <iostream>
#include <vector>

int cubic_mss(std::vector<int> vector) { // call by reference don't change original
	std::cout << "input is: " << vector.size() << " elements long" << std::endl;
	for (int i : vector) {
		std::cout << i << std::endl;
	}
	return 0;
}

int main()
{
    std::cout << "Programm running!" << std::endl; 
	std::vector<int> vector1({ 1,2,3 });
	cubic_mss(vector1);
	std::cout << "Programm ending!" << std::endl;
}

