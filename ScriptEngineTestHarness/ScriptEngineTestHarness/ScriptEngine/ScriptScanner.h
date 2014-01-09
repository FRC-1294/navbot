#ifndef SCRIPT_SCANNER_H
#define SCRIPT_SCANNER_H

class ScriptScanner
{
public:
	ScriptScanner(const char* str);
	~ScriptScanner(void);
private:
	char* str;
public:
	void eatWhitespace();
	void toEOL();

	char* nexta();
	double nextd();
	bool isAlpha(char c);
	bool hasNexta();
	bool hasNextc(char c);
	bool hasNextd();
	char peek();
};

#endif
