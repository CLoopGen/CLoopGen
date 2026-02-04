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
for (j = 0; j < Nc; j++) {
    jW[j] = j - 2;
    jE[j] = j + 2;
    if (j > 0) {
        jW[j] += 1;
    }
    if (j < Nc - 1) {
        jE[j] -= 1;
    }
}
}
