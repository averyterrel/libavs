#include <string.h>
#include <stdlib.h>

#include "strip.h"

char* lstrip(char* str, const char* stripchars) {
	return realloc(str, _lstrip(str, stripchars));
}
char* rstrip(char* str, const char* stripchars) {
}

unsigned int _lstrip(char* str, const char* stripchars) {
	unsigned int removed = strspn(str, stripchars);
	memmove(str+removed, str, strlen(str));
	return removed;
}
unsigned int _rstrip(char* str, const char* stripchars) {
}
