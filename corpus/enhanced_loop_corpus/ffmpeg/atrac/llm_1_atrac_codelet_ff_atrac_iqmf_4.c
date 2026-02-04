#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *inlo;
extern float *inhi;
extern unsigned int nIn;
extern int i;
extern float *p3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nIn / 2; i++) {
        int idx1 = 2 * i;
        int idx2 = 2 * i + 1;
        p3[4 * i + 0] = inlo[idx1] + inhi[idx1];
        p3[4 * i + 1] = inlo[idx1] - inhi[idx1];
        if (idx1 + 1 < nIn) {
            p3[4 * i + 2] = inlo[idx2] + inhi[idx2];
            p3[4 * i + 3] = inlo[idx2] - inhi[idx2];
        }
    }
}
