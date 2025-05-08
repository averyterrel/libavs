#include "test.h"
#include "../_avs.h"

#ifdef __POSIX_VISIBLE
#undef __POSIX_VISIBLE
#endif
#include "../mkstemp.h"

#include <unistd.h>

int main(void) {
	int ret = 0;
	int fd;
	/* POSIX minimum */
	PASSWiO(fd = mkstemp("XXXXXX"), -1);
	if (fd != -1) close(fd);
	PASSWiO(fd = mkstemp("X"), -1);
	if (fd != -1) close(fd);
	return ret;
}
