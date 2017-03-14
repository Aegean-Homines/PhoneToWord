#include "phone2word.h"

void all_combinations_aux(std::string const & input, std::map<char, std::string>& keypad, std::string & word, std::vector<std::string> & combinations) {
	std::string possibleChars = keypad[input[0]];
	std::string rest_numbers = input.substr(1, input.size() - 1);
	std::string::iterator iter = possibleChars.begin();
	std::string::iterator end = possibleChars.end();

	if(rest_numbers.size() == 0) {

		while (iter != end) {
			word.push_back(*iter);
			combinations.push_back(word);
			word.pop_back();
			++iter;
		}
	}

	while (iter != end) {
		word.push_back(*iter);
		all_combinations_aux(rest_numbers, keypad, word, combinations);
		word.pop_back();
		++iter;
	}
}


std::vector<std::string> all_combinations(std::string const & phone_number, std::map<char, std::string>& keypad)
{	
	std::string word;
	std::vector<std::string> combinations;
	all_combinations_aux(phone_number, keypad, word, combinations);
	return combinations;
}

