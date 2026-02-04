#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *v0;
extern double *v1;
extern double *v2;
extern double *v3;
extern double *w;
extern int len;
extern int i;
extern double a0;
extern double a1;
extern double a2;
extern double a3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced computational intensity with halved effective trip count and simplified arithmetic
    int i;
    for (i = 0; i < len; i += 2) {
        // Combine two iterations into one with reduced operation count per element
        double combined_a = (a0 + a1 + a2 + a3) * 0.5;  // Reduced coefficient set
        if (i < len) {
            w[i] += combined_a * (v0[i] + v1[i] + v2[i] + v3[i]);
        }
        if (i + 1 < len) {
            w[i+1] += combined_a * (v0[i+1] + v1[i+1] + v2[i+1] + v3[i+1]);
        }
    }
}
