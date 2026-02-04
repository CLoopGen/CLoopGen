#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *v0;
extern double *v1;
extern double *v2;
extern double *v3;
extern double *w;
extern int i;
extern int len2;
extern double sum00;
extern double sum10;
extern double sum20;
extern double sum30;
extern double w_val0;
extern double sum01;
extern double sum11;
extern double sum21;
extern double sum31;
extern double w_val1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with decoupled accumulation and increased trip count via scalar expansion
    // Loop now runs over 2*len2 to process one component per iteration, reducing data reuse but increasing trip count
    int j;
    for (j = 0; j < 2 * len2; j++) {
        int idx = j / 2;  // Original vector index
        int offset = j % 2;
        double val_w = w[j];
        if (offset == 0) {
            sum00 += v0[2 * idx] * val_w;
            sum10 += v1[2 * idx] * val_w;
            sum20 += v2[2 * idx] * val_w;
            sum30 += v3[2 * idx] * val_w;
        } else {
            sum01 += v0[2 * idx + 1] * val_w;
            sum11 += v1[2 * idx + 1] * val_w;
            sum21 += v2[2 * idx + 1] * val_w;
            sum31 += v3[2 * idx + 1] * val_w;
        }
    }
}
