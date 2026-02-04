#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src0;
extern  float *src1;
extern  float *win;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_s0, temp_s1, temp_wi, temp_wj;
    for (i = -len, j = len - 1; i < 0; i++, j--) {
        temp_s0 = src0[i];
        temp_wj = win[j];  // Load wj early to create dependency on j before s1
        temp_s1 = src1[j];
        temp_wi = win[i];

        // Introduce artificial sequential dependency: dst[i] must be computed before dst[j]
        float interm1 = temp_s0 * temp_wj;
        float interm2 = temp_s1 * temp_wi;
        dst[i] = interm1 - interm2;
        
        // dst[j] now depends on values computed in this iteration (RAW on interm1, interm2)
        dst[j] = temp_s0 * temp_wi + temp_s1 * temp_wj;
    }
}
