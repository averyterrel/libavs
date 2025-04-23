#include <string.h>
#include <stdlib.h>

#include "lstrip.h"

char* lstrip(char* str, const char* stripchars) {
	return realloc(str, _lstrip(str, stripchars));
}

unsigned int _lstrip(char* str, const char* stripchars) {
	unsigned int removed = strspn(str, stripchars);
	memmove(str+removed, str, strlen(str));
	return removed;
}
