#include "Subject.h"
#include "Wrapper.h"
using namespace std;

int main()
{
	Subject subj;
	Wrapper wrapper(&subj, &Subject::f2, { { "arg1",0 }, { "arg2", 0 } });
	/*Engine engine;*/
	/*engine.register_command(&wrapper, "command1");*/

	return 0;
}
