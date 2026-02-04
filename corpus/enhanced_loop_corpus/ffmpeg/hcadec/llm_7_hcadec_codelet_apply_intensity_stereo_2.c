#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int band_count;
extern float ratio_l;
extern float ratio_r;
extern float *c1;
extern float *c2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *c1_local = c1;
    float *c2_local = c2;
    for (int i = 0; i < band_count; i++) {
        c2_local[i] = c1_local[i] * ratio_r;
        c1_local[i] *= ratio_l;
    }
    c1 += band_count;
    c2 += band_count;
}
