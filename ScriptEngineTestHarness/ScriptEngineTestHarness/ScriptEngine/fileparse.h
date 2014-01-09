#ifndef FILEPARSE_H
#define FILEPARSE_H

#include <stdlib.h>
#include <list>

struct FileParseToken
{
	enum TokenType
	{
		kFunction,
		kLoop
	};
	
	TokenType type;
	std::list<FileParseToken*>* children;
	char* funcName;
	float dt;
	int loopCount;
	int loopPosition;
	
	//
};

class fileparse
{
public:
	static std::list<FileParseToken*>* parseCompletely(const char* str);
};


#endif
