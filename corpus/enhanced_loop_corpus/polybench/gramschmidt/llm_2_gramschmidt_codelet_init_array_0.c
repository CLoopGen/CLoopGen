#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1000][1200];
extern double Q[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access pattern to column-major (interchanged loops) for better spatial locality in column-wise storage
    for (j = 0; j < n; j++)
        for (i = 0; i < m; i++) {
            A[i][j] = (((double)((i * j) % m) / m) * 100) + 10;
            Q[i][j] = 0.;
        }
}
