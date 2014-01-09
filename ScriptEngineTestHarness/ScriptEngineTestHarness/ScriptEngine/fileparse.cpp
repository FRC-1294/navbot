#include "fileparse.h"

#include <string.h>

#include "ScriptScanner.h"
#include "streq.h"

#define DIGITS "-0.123456789"
#define WHITESPACE_CHARS " \n\r\t"

FileParseToken* parseOneToken(ScriptScanner* s)
{
	FileParseToken* token = new FileParseToken;
	token->dt = s->nextd();

	s->eatWhitespace();
	s->hasNextc(':');
	s->eatWhitespace();

	char* func = s->nexta();

	if (streq(func, "loop"))	// We've hit a loop
	{
		token->type = FileParseToken::kLoop;

		s->eatWhitespace();
		int loopCount = (int)s->nextd();
		token->loopPosition = token->loopCount = loopCount;
		//s->toEOL();
		s->eatWhitespace();
		s->hasNextc('{');
		s->toEOL();

		token->children = new std::list<FileParseToken*>();

		while (!s->hasNextc('}'))
		{
			token->children->push_back(parseOneToken(s));
		}

		s->toEOL();
	}
	else
	{
		token->type = FileParseToken::kFunction;
		token->funcName = func;
		s->toEOL();
	}

	return token;
}

std::list<FileParseToken*>* fileparse::parseCompletely(const char* str)
{
	std::list<FileParseToken*>* lst = new std::list<FileParseToken*>();

	ScriptScanner* s = new ScriptScanner(str);

	while (s->peek() != '\0')
	{
		lst->push_back(parseOneToken(s));
	}

	delete s;

	return lst;
}



