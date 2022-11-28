#include "Wrapper.h"
#include <map>
#include <iostream>
int Wrapper::execute(const std::map<std::string, int>& user_args) {
	std::vector<int> formed_call_args;
	for (auto it = _init_args.begin(); it != _init_args.end(); it++) {
		if (user_args.find(it->first) != user_args.end()) {
			formed_call_args.push_back(user_args.find(it->first)->second);
		}
		else {
			std::cout << "notice that some arguments were set by default" << std::endl;
			formed_call_args.push_back(it->second);
		}
	}
	return _wrapped_method(formed_call_args);
}
bool Wrapper::_validate_data(const std::vector<std::pair<std::string, int>>& arg_list) {
	for (auto it = arg_list.begin(); it != arg_list.end(); it++) {
		for (auto n_it = std::next(it, 1); n_it != arg_list.end(); n_it++) {
			if (it->first == n_it->first) {
				return false;
			}
		}
	}
	return true;
}
