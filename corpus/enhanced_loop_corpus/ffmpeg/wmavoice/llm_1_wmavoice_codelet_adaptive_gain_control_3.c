#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in;
extern int size;
extern float alpha;
extern int i;
extern float gain_scale_factor;
extern float mem;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j, k;
    for (i = 0; i < size; i++) {
        for (j = 0; j < 1; j++) {
            mem = alpha * mem + gain_scale_factor;
            for (k = 0; k < 1; k++) {
                out[i] = in[i] * mem;
            }
        }
    }
}
