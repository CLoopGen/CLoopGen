#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern int r;
extern int s;
extern double (*B)[2000][2000];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive row-major linear indexing to improve spatial locality
    // Flatten the 2D array access into a single loop with sequential memory access
    int i;
    double *Ap = &A[0][0];
    double *Bp = &(*B)[0][0];
    for (i = 0; i < n * n; ++i)
        Ap[i] = Bp[i];
}
