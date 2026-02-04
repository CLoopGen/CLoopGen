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
    // Variant 2: Use consecutive row-major linear indexing to improve spatial locality
    // Flatten the 2D array access into a 1D pattern using pointer arithmetic for contiguous access
    double *pA = &A[0][0];  // Base pointer to start of A
    for (i = 0; i < n; i++) {
        double ui1 = u1[i];  // Load once per row
        double ui2 = u2[i];
        int index = i * n;   // Row offset
        for (j = 0; j < n; j++) {
            // Access A[i][j] as pA[index + j] – consecutive memory access
            pA[index + j] = pA[index + j] + ui1 * v1[j] + ui2 * v2[j];
        }
    }
}
