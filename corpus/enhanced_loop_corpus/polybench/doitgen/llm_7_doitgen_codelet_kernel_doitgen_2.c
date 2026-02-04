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
for (r = 0; r < nr; r++)
    for (q = 0; q < nq; q++) {
        // Eliminate the intermediate sum array and fuse loops
        // This introduces loop-carried dependence on A[r][q][p] via immediate read-after-write
        for (p = 0; p < np; p++) {
            double sum_val = 0.0;
            for (s = 0; s < np; s++)
                sum_val += A[r][q][s] * C4[s][p];
            A[r][q][p] = sum_val;  // Immediate write, potential RAW if reused in same iteration space
        }
    }
}
