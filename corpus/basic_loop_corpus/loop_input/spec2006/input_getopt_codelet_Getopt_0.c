#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

struct opt_s {
    char *name;
    int single;
    int argtype;
};

struct opt_s *opt;
int nopts;
int i;
char *optptr;
int opti;

#define DATA_SIZE (128 << 20) // 128 MB

void init_vars() {
    nopts = 10000;
    opt = malloc(nopts * sizeof(struct opt_s));
    if (!opt) exit(1);

    for (int idx = 0; idx < nopts; idx++) {
        opt[idx].single = (idx % 3 == 0) ? 1 : 0;
        opt[idx].argtype = idx % 4;
        opt[idx].name = malloc(3);
        if (!opt[idx].name) exit(1);
        opt[idx].name[0] = 'x';
        opt[idx].name[1] = 'a' + (idx % 26);
        opt[idx].name[2] = '\0';
    }

    optptr = malloc(1);
    if (!optptr) exit(1);
    *optptr = 'a'; // Match the second character of some opt[i].name

    i = 0;
    opti = -1;
}