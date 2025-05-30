#pragma once
#include <string.h>
#include <stdio.h>

#ifdef AVS_DEBUG
#define avs_debug(...) {fprintf(stderr, __VA_ARGS__);}
#else
#define avs_debug(...) {}
#endif

#define STREQ(a, b) ((a != NULL && b != NULL) && strcmp(a, b) == 0)

#if defined(AVS_RELEASE) || defined(AVS_NO_UNUSED_VAR)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif
static char* portable_file_charset = \
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!%()+,-.:=[]^_";
#if defined(AVS_RELEASE) || defined(AVS_NO_UNUSED_VAR)
#pragma GCC diagnostic pop
#endif
