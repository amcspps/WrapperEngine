#include "Subject.h"
#include "Wrapper.h"
#include "Engine.h"
#include <iostream>
using namespace std;

int main()
{
	Subject subj;
	Wrapper wrapper1(&subj, &Subject::f1, { { "arg1", 0 } });
	Wrapper wrapper2(&subj, &Subject::f2, { { "arg2", 0 }, { "arg1", 0 } });
	Wrapper wrapper_some_args_default(&subj, &Subject::f2, { { "arg2", 0 }, { "arg1", 0 } });
	try {
		Wrapper exc_wrapper_eq_args(&subj, &Subject::f3, { { "arg1",0 }, { "arg2", 0 }, { "arg2", 0 } });
	}
	catch (invalid_argument& exc) {
		cout << exc.what() << endl;
	}
	try {
		Subject* nullsubj = nullptr;
		Wrapper exc_wrapper_nullsubj(nullsubj, &Subject::f3, { { "arg1",0 }, { "arg3", 0 }, { "arg2", 0 } });
	}
	catch (invalid_argument& exc) {
		cout << exc.what() << endl;
	}
	try {
		Subject subj;
		Wrapper exc_wrapper_arg_count(&subj, &Subject::f2, { { "arg1",0 }, { "arg3", 0 }, { "arg2", 0 } });
	}
	catch (invalid_argument& exc) {
		cout << exc.what() << endl;
	}
	
	try {
		Engine engine;
		Wrapper* wrapper_null_command = nullptr;
		engine.register_command(wrapper_null_command, "wrapper_nullptr_command");
	}
	catch (exception& exc) {
		cout << exc.what() << endl;
	}
	try {
		Engine engine;
		engine.execute("unknown_command", { {"arg1",0 } });
	}
	catch (exception& exc) {
		cout << exc.what() << endl;
	}
	Engine engine;
	engine.register_command(&wrapper1, "command1");
	engine.register_command(&wrapper2, "command2");
	engine.register_command(&wrapper_some_args_default, "command3");
	cout << engine.execute("command1", { { "arg1", 1 } }) << endl << engine.execute("command2", { { "arg1", 2 }, { "arg1", 1 } }) << endl
		<< engine.execute("command3", { { "arg1", 3 } }) << endl;
	return 0;
}
