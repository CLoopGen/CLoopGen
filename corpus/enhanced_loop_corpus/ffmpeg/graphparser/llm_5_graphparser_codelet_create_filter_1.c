#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *name;
extern char name2[30];
extern  char *inst_name;
extern  char *filt_name;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; name2[k] && !(name2[k] == '@' && name[k + 1]); k++) {
    }
    if (name2[k] == '@' && name[k + 1]) {
        name2[k] = 0;
        inst_name = name;
        filt_name = name2;
    }
}
