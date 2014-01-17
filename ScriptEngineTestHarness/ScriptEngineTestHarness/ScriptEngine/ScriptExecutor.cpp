
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
	// For every token in the list of tokens
	for (auto i = tokens->begin(); i != tokens->end(); i++)
	{
		auto f = *i;

		// If our token is a loop...
		if (f->type == FileParseToken::kLoop)
		{
			// ...call unroll n times for our children so that each of them gets added to the queue.
			for (int i = 0; i < f->loopCount; i++)
			{
				unrollLoopsImpl(f->children, output);
			}
		}
		else
		{
			// Otherwise, just push the token onto the queue.
			output->push_back(f);
		}
	}
}

std::list<FileParseToken*>* ScriptInterpreter::unrollLoops(std::list<FileParseToken*>* tokens)
{
	std::list<FileParseToken*>* output = new std::list<FileParseToken*>();

	// Hand the objects to the recursion-capable implementation function.
	unrollLoopsImpl(tokens, output);

	return output;
}

bool ScriptInterpreter::tick(double t)
{
	if (this->isFirstRun)
	{
		t0 = t;
		this->isFirstRun = false;
	}

	while (true)
	{
		if (current == NULL)
		{
			current = tokens->front();
			tokens->pop_front();
		}

		if (current->dt + t0 > t)
		{
			break;
		}

		t0 += current->dt;

		printf("%f: %s\n", current->dt, current->funcName);

		if (streq(current->funcName, "return"))
		{
			return true;
		}

		auto h = findHandler(current->funcName);
		if (h != NULL)
		{
			h->exec();
		}

		current = NULL;
	}

	return false;
}