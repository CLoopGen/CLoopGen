#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *data;
extern int len;
extern double *w_data;
extern int i;
extern int n2;
extern double w;
extern double c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_w = 1.0;
    for (i = 0; i < n2; i++) {
        w = c - i - 1.;
        w = 1. - (w * w) + prev_w; // Introduce loop-carried dependence: prev_w from previous iteration
        w_data[i] = data[i] * w;
        w_data[len - 1 - i] = data[len - 1 - i] * w;
        prev_w = w; // Create WAW and RAW dependency across iterations
    }
}
