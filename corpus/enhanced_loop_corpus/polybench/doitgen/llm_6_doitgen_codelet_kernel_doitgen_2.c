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
        // Introduce temporary array to eliminate WAW and WAR dependencies
        double temp_sum[160];
        for (p = 0; p < np; p++) {
            temp_sum[p] = 0.;
            for (s = 0; s < np; s++)
                temp_sum[p] += A[r][q][s] * C4[s][p];
        }
        // Update A only after all sum computations to remove write-read conflicts
        for (p = 0; p < np; p++)
            A[r][q][p] = temp_sum[p];
    }
}
