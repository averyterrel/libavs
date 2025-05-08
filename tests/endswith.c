#include "../endswith.h"
#include "test.h"

int main(void) {
	int ret = 0;

	PASS(endswith("", ""));
	PASS(endswith("a", "a"));
	PASS(endswith("a", ""));
	PASS(endswith("a\x01", "\x01"));
	PASS(endswith("a\0b", ""));
	char* a = "abcd";
	PASS(endswith(a, a));
	PASS(endswith("a\0b", "a"));

	FAIL(endswith(NULL, NULL));
	FAIL(endswith("a", "b"));
	FAIL(endswith("", "a"));
	FAIL(endswith("a", "aa"));
	FAIL(endswith("a", "A"));
	return 0;
}
