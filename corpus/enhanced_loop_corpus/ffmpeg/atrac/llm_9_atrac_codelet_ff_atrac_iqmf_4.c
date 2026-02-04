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
        int idx = 2 * i;
        float a = inlo[idx], b = inhi[idx];
        float c = inlo[idx + 1], d = inhi[idx + 1];
        p3[4 * i + 0] = a + b;
        p3[4 * i + 1] = a - b;
        p3[4 * i + 2] = c + d;
        p3[4 * i + 3] = c - d;
        // Additional computational intensity: inject extra arithmetic
        float avg = (a + c) * 0.5f;
        float diff_sq = (b - d) * (b - d);
        p3[4 * i + 4] = avg;
        p3[4 * i + 5] = diff_sq;
    }
}
