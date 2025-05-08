#include "read_line.h"
#include "_avs.h"

#include <stdio.h>
#include <stdlib.h>

char* read_line(FILE* file) {
	if (!file) {
		avs_debug("read_line: *file was NULL\n");
		return NULL;
	}

	int bufsz = 128;
	int len = 0;
	int c;
	char* buf = malloc(bufsz);
	if (!buf) {
		avs_debug("read_line: allocation failed\n");
		return NULL;
	}

	while ((c = fgetc(file)) != EOF && c != '\n') {
		if (len + 1 >= bufsz) {
			bufsz *= 2;
			char* newbuf = realloc(buf, bufsz);
			if (!newbuf) {
				avs_debug("read_line: reallocation failed\n");
				free(buf);
				return NULL;
			}
			buf = newbuf;
		}
		buf[len++] = (char)c;
	}

	if (len == 0 && c == EOF) {
		avs_debug("read_line: reached EOF\n");
		free(buf);
		return NULL;
	}
	buf[len] = '\0';
	return buf;
}
