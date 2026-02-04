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
    int outer_i;
    int chunk = 1;
    for (outer_i = 0; outer_i < size; outer_i += chunk) {
        for (i = outer_i; i < size && i < outer_i + chunk; i++) {
            out[i] = lpc[i] * fac;
            fac *= gamma;
        }
    }
}
