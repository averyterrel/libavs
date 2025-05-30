#pragma once
#include "../_avs.h"
#include <stdio.h>
#include "../portability/bool.h"

#define PASS(test) \
if ((test) != true) { \
	ret++; \
	printf("%s failed\n", #test); \
}

#define PASSWiO(test, retcode) \
if ((test) == retcode) { \
	ret++; \
	printf("%s failed with %d\n", #test, retcode); \
}

#define FAIL(test) \
if ((test) != false) { \
	ret++; \
	printf("%s erroneously passed\n", #test); \
}
