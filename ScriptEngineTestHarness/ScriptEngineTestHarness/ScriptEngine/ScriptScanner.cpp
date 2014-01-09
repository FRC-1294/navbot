#include "ScriptScanner.h"

#include <stdlib.h>
#include <string.h>

#define DIGITS "-0.123456789"
#define WHITESPACE_CHARS " \n\r\t"


bool strcont(char c, char* str)
{
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] == c)
			return 1;
	}

	return 0;
}

ScriptScanner::ScriptScanner(const char* str)
{
	int len = strlen(str) + 1;
	this->str = new char[len];
	memcpy(this->str, str, len);
}

ScriptScanner::~ScriptScanner(void)
{
}

bool ScriptScanner::isAlpha(char c)
{
	return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}
bool ScriptScanner::hasNexta()
{
	return this->isAlpha(this->str[0]);
}
bool ScriptScanner::hasNextc(char c)
{
	if (this->str[0] == c)
	{
		this->str++;

		return true;
	}

	return false;
}
bool ScriptScanner::hasNextd()
{
	return strcont(this->str[0], DIGITS);
}
char* ScriptScanner::nexta()
{
	char* buf = new char[strlen(this->str)];

	int i = 0;

	while (this->isAlpha(this->str[0]))
	{
		buf[i++] = this->str[0];

		this->str++;
	}

	buf[i] = '\0';

	this->eatWhitespace();

	return buf;
}
double ScriptScanner::nextd()
{
	char* buf = new char[strlen(this->str)];
	int i = 0;

	while (strcont(this->str[0], DIGITS))
	{
		buf[i++] = this->str[0];

		this->str++;
	}

	buf[i] = '\0';

	double val = atof(buf);

	this->eatWhitespace();

	return val;
}

void ScriptScanner::eatWhitespace()
{
	while (strcont(this->str[0], WHITESPACE_CHARS)) this->str++;
}
void ScriptScanner::toEOL()
{
	while (this->str[0] != '\n') this->str++;
	this->str++;
}

char ScriptScanner::peek()
{
	return *this->str;
}
