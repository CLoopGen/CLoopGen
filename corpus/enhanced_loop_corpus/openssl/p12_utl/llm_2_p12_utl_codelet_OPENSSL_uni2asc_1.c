#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *uni;
extern int unilen;
extern int i;
extern char *asctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < unilen; j += 2) {
        int idx = j >> 1;
        asctmp[idx] = uni[j];
    }
}
