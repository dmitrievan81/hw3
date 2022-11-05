#include <iostream>
#include <string>
#include "rundom_value.h"
#include "high_scores.h"
#include "argument.h"

int main(int argc, char** argv) {

	bool is_table = false;
	bool is_max = false;
	int max = 0;
	int res;
	int default_max = 100;

	res = get_arg(argc, argv, is_table, is_max, max);
	
	if (res == -1) {
		std::cout << "Parameter sequence is not correct" << std::endl;
		return -1;
	}
	
	if (is_table) {
		res = init_high_scores();
		return res;
	}
	
	if(is_max) {
		if(max == 0){
			max = default_max;
		}
	}

	if(max == 0) {
		max = default_max;
	}
	
	const int target_value = guess_the_number(max);
	
	int current_value = 0;
	bool not_win = true;
	int attempt_value = 0;
	std::cout << "Guess the number from 0 to "; 
	std::cout << max;
	std::cout << std::endl;
	std::cout << "Enter your guess:" << std::endl;
	
	do {
		
		std::cin >> current_value;
		
		if (current_value < target_value) {
			std::cout << "greater than " << current_value << std::endl;
			attempt_value++;
		}
		else if (current_value > target_value) {
			std::cout << "less than " << current_value << std::endl;
			attempt_value++;
		}
		else {
			std::cout << "you win!" << std::endl;
			not_win = false;
			break;
		}

	} while(true);

	res = init_high_scores();

	return 0;
}