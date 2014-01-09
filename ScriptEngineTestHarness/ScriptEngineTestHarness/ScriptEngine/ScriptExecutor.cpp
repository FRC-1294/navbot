
#include "ScriptExecutor.h"
#include "streq.h"

CmdHandler* ScriptInterpreter::findHandler(const char* token)
{
	for (auto i = handlers->begin(); i != handlers->end(); i++)
	{
		if (streq((*i)->k, token))
		{
			return (*i)->v;
		}
	}

	return NULL;
}

void unrollLoopsImpl(std::list<FileParseToken*>* tokens, std::list<FileParseToken*>* output)
{
	for (auto i = tokens->begin(); i != tokens->end(); i++)
	{
		auto f = *i;

		if (f->type == FileParseToken::kLoop)
		{
			for (int i = 0; i < f->loopCount; i++)
			{
				unrollLoopsImpl(f->children, output);
			}
		}
		else
		{
			output->push_back(f);
		}
	}
}

std::list<FileParseToken*>* ScriptInterpreter::unrollLoops(std::list<FileParseToken*>* tokens)
{
	std::list<FileParseToken*>* output = new std::list<FileParseToken*>();

	unrollLoopsImpl(tokens, output);

	return output;
}

void ScriptInterpreter::tick(double t)
{
	if (this->isFirstRun)
	{
		t0 = t;
	}

	while (true)
	{
		if (current == NULL)
		{
			current = tokens->front();
			tokens->pop_front();
		}

		if (current->dt + t0 < t)
		{
			break;
		}

		findHandler(current->funcName)->exec();
	}
}