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
extern double a0;
extern double a1;
extern double a2;
extern double a3;
extern double tmp0;
extern double tmp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process even and odd indices separately with stride of 2
    // This changes access pattern from sequential pairs to strided traversal
    int n = len2 * 2;

    // Process even indices: 0, 2, 4, ..., 2*len2-2
    for (i = 0; i < n; i += 2) {
        tmp0 = w[i] + a0 * v0[i] + a1 * v1[i] + a2 * v2[i] + a3 * v3[i];
        w[i] = tmp0;
    }

    // Process odd indices: 1, 3, 5, ..., 2*len2-1
    for (i = 1; i < n; i += 2) {
        tmp1 = w[i] + a0 * v0[i] + a1 * v1[i] + a2 * v2[i] + a3 * v3[i];
        w[i] = tmp1;
    }
}
