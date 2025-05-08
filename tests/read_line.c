#include "test.h"
#include "../read_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

void cleanup(void);

int fd;
char* fname;
FILE* f;

int main(void) {
	atexit(cleanup);
	int ret = 0;

	fname = strdup("./XXXXXX");
	fd = mkstemp(fname); /* assumes you have mkstemp */
	if (!fd) {
		return -1;
	}
	close(fd);

	printf("fname: %s\n", fname);
	f = fopen(fname, "rw");
	if (!f) return -1;
	int written = write(fd, "a\n\nb\nc\n4\n", 9);
	printf("Written: %d\n", written);
	fseek(f, 0, SEEK_SET);
	char* x = malloc(200);
	fread(x, 9, 1, f);
	printf("buf: %s\n", x);
	fclose(f);

	f = fopen(fname, "r");
	PASS(STREQ(read_line(f), "a"));
	PASS(STREQ(read_line(f), ""));
	PASS(STREQ(read_line(f), "b"));
	PASS(STREQ(read_line(f), "c"));
	PASS(STREQ(read_line(f), "4"));
	FAIL(STREQ(read_line(f), NULL));
	return ret;
}

void cleanup(void) {
	struct stat pstat;
	if (f) fclose(f);
	if (fname && stat(fname, &pstat) == 0) unlink(fname);
}
