#include "startswith.h"

#include <stddef.h>
#include <string.h>

bool endswith(const char * a, const char * b) {
	size_t as = strlen(a);
	size_t bs = strlen(b);
	if (as <= bs) return false;
	return memcmp(a + as - bs, b, bs) == 0;
}
