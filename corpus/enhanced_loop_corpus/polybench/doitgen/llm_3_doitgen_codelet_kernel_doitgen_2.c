#include <stdio.h>

#include <inttypes.h>

extern int nr;
extern int nq;
extern int np;
extern double A[150][140][160];
extern double C4[160][160];
extern double sum[160];
extern int r;
extern int q;
extern int p;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern to stride by 2, then handle remainder
// This creates a strided access pattern with improved spatial locality in some cache models
for (r = 0; r < nr; r++)
    for (q = 0; q < nq; q++) {
        // First pass: even indices (strided access)
        for (p = 0; p < np; p += 2) {
            sum[p] = 0.;
            for (s = 0; s < np; s++)
                sum[p] += A[r][q][s] * C4[s][p];
        }
        // Second pass: odd indices
        for (p = 1; p < np; p += 2) {
            sum[p] = 0.;
            for (s = 0; s < np; s++)
                sum[p] += A[r][q][s] * C4[s][p];
        }
        // Update A with strided write
        for (p = 0; p < np; p += 2)
            A[r][q][p] = sum[p];
        for (p = 1; p < np; p += 2)
            A[r][q][p] = sum[p];
    }
}
