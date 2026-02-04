#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Pointer-Based Access (flatten 2D to 1D for spatial locality)
    double *Ap = &A[0][0];
    double *Bp = &(*B)[0][0];
    int total_elements = n * n;
    for (int idx = 0; idx < total_elements; ++idx)
        Ap[idx] = Bp[idx];
}
