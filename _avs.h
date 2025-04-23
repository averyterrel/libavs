#pragma once
#ifndef _AVS_H
#define _AVS_H
#include <string.h>

#define STREQ(a, b) (strcmp(a, b) == 0)
static char* portable_file_charset = \
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!%()+,-.:=[]^_";

#endif /* _AVS_H */
