#include <iostream>
#include "Vector3.hpp"

int main()
{
	std::cout << "Hello" << std::endl;

	Vector3 test { 1.0, 2.0, 3.0 };

	for (int i = 0; i < 3; i++)
		std::cout << test[i] << std::endl;

	return 0;
}