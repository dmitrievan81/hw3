#include <iostream>
#include <string>
#include <sstream>

int get_arg(int argc, char** argv, bool& is_table, bool& is_max, int& max) {

	// argc - it is a count of arguments
	// But there is some detail - OS always pass one system argument - the name of the executable
	// So, is the application was executed without arguments at all, argc will be still == 1

	is_max = false;
	is_table = false;
	
	// To check - does use print some other argument we should check if the argc >= 2
	if (argc >= 2) {
		// std::cout << "We have one more argument!" << std::endl;
		std::cout << "argv[1] = " << argv[1] << std::endl;

		std::string arg1_value{ argv[1] };
		if (arg1_value == "-max") {
			std::cout << "-max argument was detected!" << std::endl;
			
			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:
			int parameter_value = 0;
			if (argc < 3) {
				std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
				return -1;
			}
			is_max = true;
			// We need to parse the string to the int value
			max = std::stoi(argv[2]);
			//std::cout << "The '-parameter' value = " << parameter_value << std::endl;
		} else if (arg1_value == "-table") {
			std::cout << "-table option was detected!" << std::endl;
			// We've detected the '-parameter' argument. And we extect that after this argument there is a value:
			int parameter_value = 0;
			is_table = true;
			
		}
	} 
	
	return 0;

}