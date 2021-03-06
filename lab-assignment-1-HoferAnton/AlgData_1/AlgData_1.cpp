// AlgData_1.cpp : contains main
//

//#include "pch.h" // precompiled header file
#include <iostream>
#include <vector>

/*
implementation of cubic algorithm to solve the Maximum Subsequence Sum Problem
*/
int cubic_mss(std::vector<int> vector) {
	int maxSum;
	if (vector.size() > 0) // exception for empty vector
		maxSum = vector[0]; // some start value
	else
		maxSum = 0; // 
	for (int i = 0; i < vector.size(); i++) {
		for (int j = i; j < vector.size(); j++) {
			int thisSum = 0;
			for (int k = i; k <= j; k++) {
				thisSum += vector[k];
				if (thisSum > maxSum) {
					maxSum = thisSum;
				}
			}
		}
	}
	return maxSum;
}

/*implementatio of quadratic algorithm to solve Maximum Subsequence Sum Problem*/

int quadratic_mss(std::vector<int> vector) {
	int maxSum;
	if (vector.size() > 0) // exception for empty vector
		maxSum = vector[0]; // some start value
	else
		maxSum = 0;
	for (int i = 0; i < vector.size(); i++) {
		int thisSum = 0;
		for (int j = i; j < vector.size(); j++) {
			thisSum = thisSum + vector[j];
			if (thisSum > maxSum) {
				maxSum = thisSum;
			}
		}
	}
	return maxSum;
}


/*implementatio of quadratic algorithm to solve Maximum Subsequence Sum Problem*/

int sequential_mss(std::vector<int> vector) {
	int maxSum = 0;
	int thisSum = 0;
	for (int i = 0; i < vector.size(); i++) {
		thisSum = thisSum + vector[i];
		if (thisSum > maxSum) {
			maxSum = thisSum;
			thisSum = 0;
		}
		else if (thisSum < 0) {
			thisSum = 0;
		}
	}
	return maxSum;
}

/*main function containing test cases*/
int main()
{
    std::cout << "Programm running!" << std::endl; 

	std::cout << "test cubic function:" << std::endl;
	{
		std::vector<int> test_vector_null({}); // empty list
		std::cout << "should be 0, Function calculated: " << cubic_mss(test_vector_null) << std::endl;
		std::vector<int> test_vector_1({ 1 }); // test for one element in the list
		std::cout << "should be 1, Function calculated: " << cubic_mss(test_vector_1) << std::endl;
		std::vector<int> test_vector_class({ 5, -17, 12, 5, -10, 6, 4, 8, -5, -10, -17, 22, 1 }); // test for list in class
		std::cout << "should be 25, Function calculated: " << cubic_mss(test_vector_class) << std::endl;

		std::vector<int> test_vector_10({ 1, 2, 3, 4 }); // test for general purpose
		std::cout << "should be 10, Function calculated: " << cubic_mss(test_vector_10) << std::endl;
		std::vector<int> test_vector_negative({ -5, -3, -1, -3, -2 }); // list of negative numbers
		std::cout << "should be -1, Function calculated: " << cubic_mss(test_vector_negative) << std::endl;
	}

	std::cout << "test quadratic function:" << std::endl;
	{
		std::vector<int> test_vector_null({}); // empty list
		std::cout << "should be 0, Function calculated: " << quadratic_mss(test_vector_null) << std::endl;
		std::vector<int> test_vector_1({ 1 }); // test for one element in the list
		std::cout << "should be 1, Function calculated: " << quadratic_mss(test_vector_1) << std::endl;
		std::vector<int> test_vector_class({ 5, -17, 12, 5, -10, 6, 4, 8, -5, -10, -17, 22, 1 }); // test for list in class
		std::cout << "should be 25, Function calculated: " << quadratic_mss(test_vector_class) << std::endl;
		
	}
	std::cout << "test sequential function:" << std::endl;
	{
		std::vector<int> test_vector_null({}); // empty list
		std::cout << "should be 0, Function calculated: " << quadratic_mss(test_vector_null) << std::endl;
		std::vector<int> test_vector_1({ 1 }); // test for one element in the list
		std::cout << "should be 1, Function calculated: " << quadratic_mss(test_vector_1) << std::endl;
		std::vector<int> test_vector_class({ 5, -17, 12, 5, -10, 6, 4, 8, -5, -10, -17, 22, 1 }); // test for list in class
		std::cout << "should be 25, Function calculated: " << quadratic_mss(test_vector_class) << std::endl;

	}
	std::cout << "Programm ending!" << std::endl;
}

