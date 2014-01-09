#ifndef SCRIPT_EXECUTOR_H
#define SCRIPT_EXECUTOR_H

#include "fileparse.h"
#include <list>
#include <vector>
#include <stack>

class CmdHandler
{
private:
	char* name;
public:
	CmdHandler(char* name)
	{
		this->name = name;
	}
	void exec()
	{
		printf("%s called\n", this->name);
	}
};

class ScriptInterpreter
{
	class kvp
	{
	public:
		char* k;
		CmdHandler* v;
	};

public:
	std::vector<kvp*>* handlers;
	void tick(double elapsedTime);

	ScriptInterpreter(const char* str)
	{
		this->tokens = fileparse::parseCompletely(str);
		std::list<FileParseToken*>* tokens2 = ScriptInterpreter::unrollLoops(tokens);
		delete this->tokens;
		this->tokens = tokens2;
	}
private:
	std::list<FileParseToken*>* tokens;
	
	FileParseToken* current;
	bool hasExecCurrent = false;

	fileparse* fp;

	static std::list<FileParseToken*>* unrollLoops(std::list<FileParseToken*>* tokens);

	double t0;
	bool isFirstRun = true;
	CmdHandler* findHandler(const char* token);
};

#endif
