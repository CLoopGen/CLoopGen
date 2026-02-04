#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double c[64];
extern int src[64];
extern int i;
extern int j;
extern int k;
extern double tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    for (j = 0; j < 8; j++) {
        double sum = 0.;
        for (k = 0; k < 16; k++) {
            int src_idx = (k < 8) ? (8 * i + k) : (8 * (i + 4) + (k - 8));
            int c_idx = (k < 8) ? (k * 8 + j) : ((k - 8) * 8 + j);
            sum += c[c_idx] * src[src_idx];
        }
        tmp[8 * i + j] = sum;
        tmp[8 * (i + 4) + j] = sum; // Reuse computation for reduced work
    }
}
}
