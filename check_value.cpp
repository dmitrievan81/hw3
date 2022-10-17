#include <iostream>
#include <string>
#include "rundom_value.h"
#include "high_scores.h"

int main() {

	const int target_value = guess_the_number();
	
	std::cout << "target value is " << target_value << std::endl;

	int current_value = 0;
	bool not_win = true;
	int attempt_value = 0;
	std::cout << "Guess the number from 0 to 100." << std::endl;
	std::cout << "Enter your guess:" << std::endl;
	
	do {
		
		std::cin >> current_value;
		
		if (current_value < target_value) {
			std::cout << "less than " << current_value << std::endl;
			attempt_value++;
		}
		else if (current_value > target_value) {
			std::cout << "greater than " << current_value << std::endl;
			attempt_value++;
		}
		else {
			std::cout << "you win!" << std::endl;
			not_win = false;
			break;
		}

	} while(true);

	int res = init_high_scores();

	return 0;
}