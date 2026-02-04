#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long Nc;
extern int *jE;
extern int *jW;
extern long j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < Nc; j++) {
        jW[j] = (j == 0) ? -1 : j - 1;
        jE[j] = (j == Nc - 1) ? Nc : j + 1;
    }
}
