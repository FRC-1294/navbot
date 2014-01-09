#include "streq.h"

bool streq(const char* a, const char* b)
{
	while (*a != '\0' && *b != '\0')
	{
		if (*a == *b)
		{
			a++;
			b++;
		}
		else
		{
			return false;
		}
	}

	return true;
}