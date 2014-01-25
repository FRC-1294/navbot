// ScriptEngineTestHarness.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ScriptEngine\ScriptExecutor.h"
#include <Windows.h>
#include <time.h>

union MechDriveResult
{
	struct fr
	{
		float FrontLeft, RearLeft, FrontRight, RearRight;
	} f;
	float vals[4];
};

#define FABS(x) (x < 0 ? -x : x)

void NormalizeVector(MechDriveResult* v, float m)
{
	float max = m;

	for (int i = 0; i < 4; i++)
	{
		float f = FABS(v->vals[i]);

		if (f > max)
		{
			max = f;
		}
	}

	float ratio = m / max;

	for (int i = 0; i < 4; i++)
	{
		v->vals[i] = v->vals[i] * ratio;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	MechDriveResult* m = (MechDriveResult*)malloc(sizeof(MechDriveResult));

	NormalizeVector(m, 1.0);













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

