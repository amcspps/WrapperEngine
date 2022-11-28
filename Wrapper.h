#include<vector>
#include <string>
#include <functional>

class Wrapper {
public:
	template <typename SomeClass, typename... Args>
	Wrapper(SomeClass* cls, int(SomeClass::* method)(Args...), const std::vector <std::pair<std::string, int>>& init_arg_list) {
		if (cls == nullptr) {
			throw("instance of class is nullptr");
		}
		else if (method == nullptr) {
			throw("method pointer is nullptr");
		}
		else if (init_arg_list.size() != sizeof...(Args)) {
			throw("wrong number of arguments");
		}
		else if (!_validate_data(init_arg_list)) {
			throw("Some arguments have the same key");
		}
		for (auto el : init_arg_list) {
			_args.push_back(el);
		}
		_wrapped_method = [this, cls, method](const std::vector<int>& user_args) {
			return _call(cls, method, user_args, std::make_index_sequence<sizeof...(Args)> {});
		};
	};
	//TODO: execute command when call from engine

private:
	bool _validate_data(const std::vector<std::pair<std::string, int>>& init_arg_list);
	template<typename SomeClass, typename... Args, size_t... Indices>
	int _call(SomeClass* cls, int(SomeClass::* method)(Args...),const std::vector<int> &user_args, std::index_sequence<Indices...>) {
		return((cls->*method)(user_args[Indices]...));
	}
	std::vector<std::pair<std::string, int>> _args;
	std::function <int(std::vector <int>)> _wrapped_method;
};