#include <iostream>
#include <cstdlib>
#include <ctime>

#include "rundom_value.h"

int guess_the_number() {

	std::srand(std::time(nullptr)); // use current time as seed for random generator
	return std::rand() % 100;

}