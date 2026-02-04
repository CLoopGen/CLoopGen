#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nc;
extern int *jE;
extern int *jW;
extern long j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (Nc > 0) {
    jW[0] = -1;
    jE[0] = 1;
    for (j = 1; j < Nc; j++) {
        jW[j] = jE[j - 1] - 2;
        jE[j] = jE[j - 1] + 1;
    }
}
}
