#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern double u1[2000];
extern double v1[2000];
extern double u2[2000];
extern double v2[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to stride by 2 (strided access)
    // This processes elements with a step of 2, covering even indices first, then odd if needed.
    // For correctness over the full range, we assume n is even; otherwise, handle remainder.
    int stride = 2;
    for (int s = 0; s < stride; s++) {
        for (i = s; i < n; i += stride) {
            for (j = s; j < n; j += stride) {
                A[i][j] = A[i][j] + u1[i] * v1[j] + u2[i] * v2[j];
            }
        }
    }
}
