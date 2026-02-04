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
    if (Nc > 0) {
        j = 0;
        for (long outer = 0; outer < Nc; outer++) {
            j = outer;
            jW[j] = j - 1;
            jE[j] = j + 1;
        }
    }
}
