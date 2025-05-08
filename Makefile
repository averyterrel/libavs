PREFIX = /usr/local

.PHONY: clean build all
NORM_OBJS = arena.o \
	   endswith.o \
	   fseekline.o \
	   getopt.o \
	   lstrip.o \
	   max.o \
	   memswap.o \
	   min.o \
	   read_line.o \
		 stack.o \
	   startswith.o
DEBUG_OBJS = arena_debug.o \
	endswith_debug.o \
	fseekline_debug.o \
	getopt_debug.o \
	lstrip_debug.o \
	max_debug.o \
	memswap_debug.o \
	min_debug.o \
	read_line_debug.o \
	stack_debug.o \
	startswith_debug.o
OBJS = $(NORM_OBJS) $(DEBUG_OBJS)
HEADERS = arena.h \
		  endswith.h \
		  fseekline.h \
		  getopt.h \
		  lstrip.h \
		  max.h \
		  memswap.h \
		  min.h \
		  read_line.h \
			stack.h \
		  startswith.h

all: build
build: libavs.a avs.h

distclean: clean
	$(RM) libavs.a avs.h
clean:
	$(RM) $(OBJS)

libavs.a: $(OBJS) $(NORM_OBJS) $(DEBUG_OBJS)
	$(AR) $(ARFLAGS) rcs $@ $^
avs.h: $(HEADERS)
	printf '%s\n' '#pragma once' '#ifndef _AVS_H' '#define _AVS_H' '' \
		| cat - $^ > $@
	printf '%s\n' '' '#endif /* _AVS_H */' >> $@

install: libavs.a avs.h
	install -m 644 libavs.a $(DESTDIR)$(PREFIX)/lib/
	install -m 644 avs.h $(DESTDIR)$(PREFIX)/include/

%_debug.o: %.c
	$(CC) -c -o $@ $(CFLAGS) -DAVS_DEBUG=1 $<
.c.o:
	$(CC) -c -o $@ $(CFLAGS) $<
