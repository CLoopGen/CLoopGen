#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern int *src0;
extern int len;
extern int i;
extern int *src1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float sum = 0.0F;
    for (i = 0; i < len; i++) {
        float r = src0[i] * (1.F / (2.F * 2147483647));
        r += src1[i] * (1.F / (2.F * 2147483647));
        sum += r; // Introduce loop-carried dependency (sum depends on previous iteration)
        dst[i] = sum; // WAW and WAR dependencies introduced via cumulative write
    }
}
