#pragma once
#include <string>

int save_high_score(const std::string& high_scores_filename, std::string& user_name, int attempts_count);
int read_high_score(const std::string& high_scores_filename);
int init_high_scores();