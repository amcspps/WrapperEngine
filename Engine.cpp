#include "Engine.h"
#include <iostream>

void Engine::register_command(Wrapper* wrapper, const std::string& command_name) {
	if (wrapper == nullptr) {
		throw(std::exception("command did not registered, nullptr"));
	}
	_commands.insert({ command_name, wrapper });
}
int Engine::execute(const std::string& command_name, const std::map<std::string, int>& user_args) {
	auto search_command = _commands.find(command_name);
	if (search_command != _commands.end()) {
		return search_command->second->execute(user_args);
	}
	else {
		throw(std::exception ("command not found"));
	}
};