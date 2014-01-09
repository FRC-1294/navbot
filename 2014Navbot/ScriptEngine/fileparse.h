#ifndef FILEPARSE_H
#define FILEPARSE_H

#include <stdlib.h>


struct FileParseToken
{
	enum TokenType
	{
		kFunction,
		kLoop
	};
	
	TokenType type;
	std::vector<FileParseToken> children;
	char* funcName;
	float timeLength;
	
	//
};

class fileparse
{
public:
	static std::vector<FileParseToken> parseCompletely(const char* str);
};


#endif
