#include "startswith.h"

#include <stddef.h>
#include <string.h>

bool startswith(const char * a, const char * b) {
	size_t bs = strlen(b);
	return strlen(a) >= bs && memcmp(a, b, bs) == 0;
}
