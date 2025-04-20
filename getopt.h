extern int avs_optind;
extern int avs_opterr;
extern int avs_optopt;
extern char *avs_optarg;

int avs_getopt(int argc, const char *argv[], const char *optstring);
int getopt(int argc, const char *argv[], const char *optstring);

#define getopt(argc, argv, optstring) avs_getopt(argc, argv, optstring)

#define optind avs_optind
#define opterr avs_opterr
#define optopt avs_optopt
#define optarg avs_optarg
