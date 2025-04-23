#include "startswith.h"

#include <stddef.h>
#include <string.h>

bool startswith(const char * a, const char * b) {
	if (a == NULL || b == NULL) return false;
	size_t as = strlen(a);
	size_t bs = strlen(b);
	if (as < bs) return false;
	return memcmp(a, b, bs) == 0;
}
