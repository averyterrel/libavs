#include "startswith.h"

#include <stddef.h>
#include <string.h>

bool endswith(const char * a, const char * b) {
	if (a == NULL || b == NULL) return false;
	size_t as = strlen(a);
	size_t bs = strlen(b);
	if (as == 0 && bs == 0) return true;
	if (as < bs) return false;
	return memcmp(a + as - bs, b, bs) == 0;
}
