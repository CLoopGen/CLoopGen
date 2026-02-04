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
    for (k = 0; name2[k] && name[k]; k += 2) {
        if (k % 2 == 0 && name2[k] == '@' && name[k + 1]) {
            name2[k] = 0;
            inst_name = &name[0];
            filt_name = &name2[0];
            break;
        }
    }
    if (k >= 30 && !inst_name) {
        inst_name = NULL;
        filt_name = NULL;
    }
}
