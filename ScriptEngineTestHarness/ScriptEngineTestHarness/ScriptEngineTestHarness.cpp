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

#define JOYSTICK_DEADZONE 0.5

inline float map(float x, float in_min, float in_max, float out_min, float out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
inline float dz(float x)
{
	if (fabs(x) > JOYSTICK_DEADZONE)
	{
		return map(x, JOYSTICK_DEADZONE, 1.0, 0, 1.0);
	}
	else
	{
		return 0;
	}
}


inline float fpow(float base, int power)
{
	float x = base;

	switch (power)
	{
	case 4:
		x *= base;
	case 3:
		x *= base;
	case 2:
		x *= base;
	case 1:
		return x;
	case 0:
		return 1;
	default:
		for (int i = 1; i < power; i++)
		{
			x *= base;
		}
		return x;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	float res = fpow(.1,3);




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

