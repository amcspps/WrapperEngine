#include "Subject.h"
#include <iostream>

int Subject::f1(int arg1) {
	return arg1;
}

int Subject::f2(int arg1, int arg2) {
	return arg1 + arg2;
}

int Subject::f3(int arg1, int arg2, int arg3) {
	return arg1 + arg2 + arg3;
}

Subject::Subject() {
	std::cout << "Subject created";
}