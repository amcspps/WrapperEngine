#pragma once
#include "Wrapper.h"
#include <map>
class Engine {
public:
	Engine() = default;
	Engine(const Engine&) = delete;
	Engine& operator= (Engine const&) = delete;
	~Engine() = default;
	void register_command(Wrapper* wrapper, const std::string& command_name);
	int execute(const std::string &command_name, const std::map<std::string, int> &user_args);
private:
	std::map<std::string, Wrapper*> _commands;
};