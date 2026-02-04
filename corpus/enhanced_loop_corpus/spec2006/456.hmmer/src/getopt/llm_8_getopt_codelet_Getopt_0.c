#include <stdio.h>

#include <inttypes.h>

struct opt_s {
    char *name;
    int single;
    int argtype;
};


extern struct opt_s *opt;
extern int nopts;
extern int i;
extern char *optptr;
extern int opti;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    opti = -1;
    i = 0;
    int limit = nopts * (nopts > 0 ? 1 : 0); // Ensure non-negative and avoid redundant checks
    for (; i < limit; i += 2) {
        if (i < nopts && opt[i].single == 1 && *optptr == opt[i].name[1]) {
            opti = i;
            break;
        }
        // Unroll second iteration manually to reduce loop overhead
        if (i + 1 < nopts && opt[i + 1].single == 1 && *optptr == opt[i + 1].name[1]) {
            opti = i + 1;
            break;
        }
    }
}
