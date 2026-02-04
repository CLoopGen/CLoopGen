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
for (opti = -1 , i = 0; i < nopts; i++)
    if (opt[i].single == 1 && *optptr == opt[i].name[1]) {
        opti = i;
        break;
    }

}
