.PHONY: clean build all
OBJS = arena.o \
	   arena_debug.o \
	   memswap.o \
	   read_line.o \
	   strip.o \
	   getopt.o \
	   startswith.o
HEADERS = arena.h \
		  memswap.h \
		  read_line.h \
		  strip.h \
		  getopt.h \
		  startswith.h
PREFIX = /usr/local

all: build
build: libavs.a avs.h

distclean: clean
	$(RM) libavs.a avs.h
clean:
	$(RM) $(OBJS)

libavs.a: $(OBJS)
	$(AR) rcs $@ $^

avs.h: $(HEADERS)
	cat $^ > $@

arena_debug.o:
	$(CC) -c -o $@ $(CFLAGS) -DARENA_SANITIZE=1 arena.c
.c.o:
	$(CC) -c -o $@ $(CFLAGS) $<

install: libavs.a avs.h
	install -m 644 libavs.a $(DESTDIR)$(PREFIX)/lib/
	install -m 644 avs.h $(DESTDIR)$(PREFIX)/include/
