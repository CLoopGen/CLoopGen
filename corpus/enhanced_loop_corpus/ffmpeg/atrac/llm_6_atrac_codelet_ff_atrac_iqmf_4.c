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
    float temp1, temp2, temp3, temp4;
    for (i = 0; i < nIn; i += 2) {
        temp1 = inlo[i] + inhi[i];
        temp2 = inlo[i] - inhi[i];
        temp3 = inlo[i + 1] + inhi[i + 1];
        temp4 = inlo[i + 1] - inhi[i + 1];
        p3[2 * i + 0] = temp1;
        p3[2 * i + 1] = temp2;
        p3[2 * i + 2] = temp3;
        p3[2 * i + 3] = temp4;
    }
}
