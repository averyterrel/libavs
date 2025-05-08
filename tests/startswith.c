#include "../startswith.h"
#include "test.h"

int main(void) {
	int ret = 0;

	PASS(startswith("", ""));
	PASS(startswith("a", ""));
	PASS(startswith("a", "a"));
	PASS(startswith("\x01g", "\x01"));
	PASS(startswith("a\0b", "a"));
	char* a = "abcd";
	PASS(startswith(a, a));

	FAIL(startswith(NULL, NULL));
	FAIL(startswith("a", "b"));
	FAIL(startswith("", "a"));
	FAIL(startswith("a", "aa"));
	FAIL(startswith("a", "A"));
	return 0;
}
