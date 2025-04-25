#pragma once
#include <string.h>

#ifdef _AVS_DEBUG
#define _avs_debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define _avs_debug(...)
#endif

#define STREQ(a, b) ((a != NULL && b != NULL) && strcmp(a, b) == 0)
static char* portable_file_charset = \
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!%()+,-.:=[]^_";
