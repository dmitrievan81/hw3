#include <iostream>
#include <fstream>
#include <string>

int save_high_score(const std::string& high_scores_filename, std::string& user_name, int attempts_count)
{
	std::ofstream out_file{high_scores_filename, std::ios_base::app};
	if (!out_file.is_open()) {
		std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		return -1;
	}
	
	out_file << user_name << ' ';
	out_file << attempts_count;
	out_file << std::endl;
	
	return 0;
}

int read_high_score(const std::string& high_scores_filename)
{
		std::ifstream in_file{high_scores_filename};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
			return -1;
		}
		std::string username;
		int high_score;
		std::cout << "High scores table:" << std::endl;
		while (true) {
			// Read the username first
			in_file >> username;
			// Read the high score next
			in_file >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}
			
			// Print the information to the screen
			std::cout << username << '\t' << high_score << std::endl;
		}
		
		return 0;
}

int init_high_scores() 
{
	
	const std::string high_scores_filename = "high_scores.txt";
	// Ask about name
	std::cout << "Hi! Enter your name, please:" << std::endl;
	std::string user_name;
	std::cin >> user_name;

	// Get the last high score
	std::cout << "Enter your high score:" << std::endl;
	int attempts_count = 0;
	std::cin >> attempts_count;
	if (std::cin.fail()) {
		std::cout << "Bad value!" << std::endl;
		return -1;
	}
	
	int res = save_high_score(high_scores_filename, user_name, attempts_count);
	if (res == -1) {
		return res;
	}
	
	// Read the high score file and print all results
	read_high_score(high_scores_filename);

	return 0;
}