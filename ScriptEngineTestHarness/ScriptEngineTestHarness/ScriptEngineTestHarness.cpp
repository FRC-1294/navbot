// ScriptEngineTestHarness.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ScriptEngine\ScriptExecutor.h"
#include <Windows.h>
#include <time.h>

int _tmain(int argc, _TCHAR* argv[])
{
	ScriptInterpreter* si = new ScriptInterpreter(	"0: funca();\n"
													"0: loop 5\n"
													"{\n"
														"0: loop 5\n"
														"{\n"
															"2: funcb();\n"
														"}\n"
														"2: funcc();\n"
													"}\n"
													"2 : funcd();\n"
													"0: return();\n");

	while (1)
	{
		time();
		TIME_MSt	
		si->tick();
	}

	return 0;
}

