#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "fseekline.h"

int fseekline(FILE* fp, long offset, int whence) {
	if (!fp) {
		errno = EBADF;
		return -1;
	}
	switch (whence) {
		case SEEK_SET:
		case SEEK_CUR:
		case SEEK_END:
			break;
		default:
			errno = EINVAL;
			return -1;
	}
	int nl;
	int c;
	if (whence == SEEK_END) {
		fseek(fp, 0, SEEK_END);
		for (nl = offset; offset > 0; nl++) {
			int pos;
			for (pos = ftell(fp); (c = fgetc(fp)) != EOF; pos -= 2) {
				if (c == -1) {
					return -1;
				}
				if (c == '\n') {
					break;
				}
			}
		}
		return 0;
	}
	if (whence == SEEK_SET) {
		fseek(fp, 0, SEEK_SET);
	}
	for (nl = offset; offset > 0; nl++) {
		while ((c = fgetc(fp)) != EOF) {
			if (c == -1) {
				return -1;
			}
			if (c == '\n') {
				break;
			}
		}
		if (c == EOF) {
			return EOF;
		}
	}
	if ((c = fgetc(fp)) == EOF) {
		return EOF;
	}
	if (c == -1) {
		return -1;
	}
	return 0;
}
