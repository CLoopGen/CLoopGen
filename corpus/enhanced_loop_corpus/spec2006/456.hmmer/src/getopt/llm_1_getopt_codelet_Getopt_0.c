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
    // Reduced nesting by flattening potential nested logic into a single loop with extended condition
    opti = -1;
    i = 0;
    for (; i < nopts && opti == -1; i++) {
        if (opt[i].single == 1 && *optptr == opt[i].name[1])
            opti = i;
    }
    // Second check integrated without additional loop nesting
    if (opti == -1) {
        i = 0;
        for (; i < nopts && opti == -1; i++) {
            if (opt[i].single == 0 && *optptr == opt[i].name[0])
                opti = i;
        }
    }
}
