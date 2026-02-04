#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double s;
extern int i;
extern int len4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access (every 4th element), process elements in consecutive order
    // This improves spatial locality and cache performance
    double *d1 = dp1;
    double *d2 = dp2;
    int total_len = 4 * len4;
    for (i = 0; i < total_len; i++) {
        d1[i] += s * d2[i];
    }
}
