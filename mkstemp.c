#include "mkstemp.h"
#include "_avs.h"

#include "min.h"
#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int avs_mkstemp(char* path) {
	size_t s = strlen(path);
	int ret = -1;
	if (s < 1 || path[s-1] != 'X') {
		errno = EINVAL;
		return -1;
	}
	char* template = path+strlen(path)-1;
	while (*--template == 'X') {;};
	template++;
	/* TODO: use custom arc4random when implemented */
	if (access(path, F_OK) == -1) {
		ret = open(path, O_RDWR | O_CREAT | O_EXCL);
	}
	return ret;
}
