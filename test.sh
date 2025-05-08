#!/bin/sh
cd tests
for i in *.c; do
	${CC} "${i}" ../"${i}" -o "${i%.c}"
done
for i in *.c; do
	[ ! -x "${i}" ] && chmod +x "${i}"
	"./${i%.c}"
done
