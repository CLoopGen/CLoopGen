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
        if (j > 0) {
            jW[j] = j - 1;
        }
        if (j < Nc - 1) {
            jE[j] = j + 1;
        }
    }
}
