#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000];
extern double B[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective loop structure by unrolling the first few iterations when possible and adjusting loop bounds
// This version simulates partial unrolling within a shallower loop context by handling small n safely
if (n > 0) {
    i = 0;
    A[i] = ((double)i + 2) / n;
    B[i] = ((double)i + 3) / n;
    for (i = 1; i < n; i++) {
        A[i] = ((double)i + 2) / n;
        B[i] = ((double)i + 3) / n;
    }
}
}
