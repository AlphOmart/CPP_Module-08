#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int	main() {
	int					intArr[] = {2, 4324, 42, 21, 321, 2, 63, 62, 63216};


	std::vector<int>	intVector(intArr, intArr + sizeof(intArr) / sizeof(*intArr));
	for (size_t i = 0; i < intVector.size(); i++) {
		std::cout << intVector[i] << ' ';
	}
	std:: cout << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(intVector, 42);
		std::cout << "Successfully found " << *it  << " in intVector"<< std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: Failed to find 42 in intVector" << std::endl;
	}
	try {
		easyfind(intVector, 43);
		std::cout << "Successfully found 43 in intVector" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: failed to find 43 in intVector" << std::endl;
	}
	try {
		easyfind(intVector, 2);
		std::cout << "Successfully found 42 in intVector" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: Failed to find 42 in intVector" << std::endl;
	}

	std:: cout << std::endl;
	std::list<int>		intList(intArr, intArr + sizeof(intArr) / sizeof(*intArr));
	for (std::list<int>::iterator it = intList.begin(); it != intList.end(); ++it) {
		std::cout << *it << ' ';
	}
	std:: cout << std::endl;
	try {
		easyfind(intList, 42);
		std::cout << "Successfully found 42 in intList" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: Failed to find 42 in intList" << std::endl;
	}
	try {
		easyfind(intList, 43);
		std::cout << "Error: found 43 in intList despite it not existing" << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Successfully failed to find 43 in intList" << std::endl;
	}
}