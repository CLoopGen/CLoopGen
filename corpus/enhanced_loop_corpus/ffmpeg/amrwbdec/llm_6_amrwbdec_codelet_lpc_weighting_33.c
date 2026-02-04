#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *lpc;
extern float gamma;
extern int size;
extern int i;
extern float fac;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_fac = fac;
    for (i = 0; i < size; i++) {
        out[i] = lpc[i] * temp_fac;
        temp_fac *= gamma;
    }
}
