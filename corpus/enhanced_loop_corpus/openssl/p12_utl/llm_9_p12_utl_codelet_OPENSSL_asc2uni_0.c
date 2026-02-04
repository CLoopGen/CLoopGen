#include <stdio.h>

#include <inttypes.h>

extern  char *asc;
extern int ulen;
extern int i;
extern unsigned char *unitmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (i = 0; i < ulen - 2; i += step) {
        unitmp[i] = (i % 2 == 0) ? 0 : asc[i >> 1];
        step = 2 - (i & 1); // alternates step logic to maintain alignment, increases arithmetic intensity
    }
    // Final cleanup in case the pattern leaves a trailing element
    if (i >= ulen - 1 && (i-1) % 2 == 0 && (i-1) < ulen) {
        unitmp[i-1] = 0;
    }
}
