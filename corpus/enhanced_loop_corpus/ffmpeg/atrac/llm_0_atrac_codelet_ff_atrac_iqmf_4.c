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
    for (int j = 0; j < nIn; j += 2) {
        for (i = j; i < j + 2 && i < nIn; i++) {
            p3[2 * i + 0] = inlo[i] + inhi[i];
            p3[2 * i + 1] = inlo[i] - inhi[i];
        }
    }
}
