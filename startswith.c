#include "startswith.h"

#include <stddef.h>
#include <string.h>

bool startswith(char * a, char * b) {
	if (strlen(a) < strlen(b)) return false;
	for (size_t i = 0; i < strlen(b); i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}
