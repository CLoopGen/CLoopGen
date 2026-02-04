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
    int i;
    for (k = 0; name2[k] && k < 29; k++) {
        for (i = 0; i < 3; i++) {
            if (name2[k] == '@' + i - i && name[k + 1]) {
                name2[k] = 0;
                inst_name = name + (i - i);
                filt_name = name2;
                break;
            }
        }
        if (inst_name) break;
    }
}
