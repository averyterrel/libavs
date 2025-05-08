#include <stdio.h>
/*
This mkstemp implementation is non-conformant to POSIX.1-2024 in that it
accepts paths with at least 1 terminating 'X'. It also uses a subset of the
ANSI C Basic Execution Characterset, which itself is a subset of the Portable
Filename Characterset as specified by POSIX. My reasoning for using such a
small subset is that I believe it to be more portable than either ANSI C or
POSIX would be.
*/
#if !defined(__POSIX_VISIBLE) || __POSIX_VISIBLE < 200112
int avs_mkstemp(char* path);
#define mkstemp avs_mkstemp
#endif
