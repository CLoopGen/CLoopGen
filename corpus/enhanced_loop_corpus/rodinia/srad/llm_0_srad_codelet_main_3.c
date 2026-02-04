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
    for (long i = 0; i < Nc; i++) {
        for (j = i; j <= i; j++) {
            jW[j] = j - 1;
            jE[j] = j + 1;
        }
    }
}
