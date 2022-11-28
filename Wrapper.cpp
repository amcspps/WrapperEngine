#include "Wrapper.h"

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