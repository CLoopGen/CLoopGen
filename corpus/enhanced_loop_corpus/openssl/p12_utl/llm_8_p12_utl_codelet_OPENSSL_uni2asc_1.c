#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *uni;
extern int unilen;
extern int i;
extern char *asctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < unilen; j += 4) {
        if (j + 2 < unilen) {
            asctmp[j >> 1] = uni[j];
            asctmp[(j + 2) >> 1] = uni[j + 2];
        } else if (j < unilen) {
            asctmp[j >> 1] = uni[j];
        }
    }
}
