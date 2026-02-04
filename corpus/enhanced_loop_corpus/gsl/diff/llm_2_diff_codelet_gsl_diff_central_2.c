#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int k;
extern double a[4];
extern double d[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing d[i] and a[i+k] with variable k, we precompute strides
    // and traverse the arrays with a fixed increment pattern.
    for (k = 1; k < 5; k++) {
        int stride = k;
        for (i = 0; i < 4 - k; i++) {
            int idx_d_current = i;
            int idx_d_next = i + 1;
            int idx_a_current = i;
            int idx_a_stride = i + stride;
            d[idx_d_current] = (d[idx_d_next] - d[idx_d_current]) / (a[idx_a_stride] - a[idx_d_current]);
        }
    }
}
