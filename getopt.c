#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define STREQ(a, b) (strcmp(a, b) == 0)

int avs_optind;
int avs_opterr = 1;
int avs_optopt;
char *avs_optarg;

int avs_getopt(int argc, const char * argv[], const char * optstring)
{
  static int optpos = 1;
  const char *arg;

  if (avs_optind == 0) {
    avs_optind = !!argc;
    optpos = 1;
  }

  arg = argv[avs_optind];
  if (arg && STREQ(arg, "--")) {
    avs_optind++;
    return -1;
  } else if (!arg || arg[0] != '-' || (!isalnum(arg[1]) && arg[1] != '-')) {
    return -1;
  } else {
    const char *opt = strchr(optstring, arg[optpos]);
    avs_optopt = arg[optpos];
    if (!opt) {
      if (avs_opterr && *optstring != ':')
        fprintf(stderr, "%s: illegal option: %c\n", argv[0], avs_optopt);
      if (!arg[++optpos]) {
        avs_optind++;
        optpos = 1;
      }
      return '?';
    } else if (opt[1] == ':') {
    if (arg[optpos + 1]) {
      avs_optarg = (char *)arg + optpos + 1;
      avs_optind++;
      optpos = 1;
      return avs_optopt;
    } else if (argv[avs_optind + 1]) {
      avs_optarg = (char *)argv[avs_optind + 1];
      avs_optind += 2;
      optpos = 1;
      return avs_optopt;
    } else {
      if (avs_opterr && *optstring != ':')
        fprintf(stderr,
          "%s: option requires an argument: %c\n",
          argv[0], avs_optopt);
      if (!arg[++optpos]) {
        avs_optind++;
        optpos = 1;
      }
      return *optstring == ':' ? ':' : '?';
    }
    } else {
      if (!arg[++optpos]) {
        avs_optind++;
        optpos = 1;
      }
      return avs_optopt;
    }
  }
}
