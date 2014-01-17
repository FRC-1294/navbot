// ScriptEngineTestHarness.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ScriptEngine\ScriptExecutor.h"
#include <Windows.h>
#include <time.h>

int _tmain(int argc, _TCHAR* argv[])
{
	ScriptInterpreter* si = new ScriptInterpreter("0: funca();\n"
		"0: loop 5\n"
		"{\n"
		"0: loop 5\n"
		"{\n"
		"2: funcb();\n"
		"}\n"
		"8: funcc();\n"
		"}\n"
		"3 : funcd();\n"
		"0: return();\n");

	auto t0 = GetTickCount64();

	bool cont = false;

	while (!cont)
	{
		auto t = GetTickCount64();
		auto dt = t - t0;

		//printf("%d\n", dt);
		
		Sleep(50);

		cont = si->tick(((double)dt) / 1000);
	}

	return 0;
}

