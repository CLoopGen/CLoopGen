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
long k;
for (j = 0; j < Nc; j++) {
    for (k = 0; k < 3; k++) {
        if (k == 0) {
            jW[j] = j - 1;
        } else if (k == 1) {
            jE[j] = j + 1;
        } else {
            jW[j] = (jW[j] + jE[j]) / 2;
        }
    }
}
}
