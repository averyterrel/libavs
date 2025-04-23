#include "read_line.h"

#include <stdio.h>
#include <stdlib.h>

char* read_line(FILE* file) {
	if (!file) {
		return NULL;
	}

	int bufsz = 128;
	int len = 0;
	int c;
	char* buf = malloc(bufsz);
	if (!buf) {
		return NULL;
	}

	while ((c = fgetc(file)) != EOF && c != '\n') {
		if (len + 1 >= bufsz) {
			bufsz *= 2;
			char* newbuf = realloc(buf, bufsz);
			if (!newbuf) {
				free(buf);
				return NULL;
			}
			buf = newbuf;
		}
		buf[len++] = (char)c;
	}

	if (len == 0 && c == EOF) {
		free(buf);
		return NULL;
	}
	buf[len] = '\0';
	return buf;
}
