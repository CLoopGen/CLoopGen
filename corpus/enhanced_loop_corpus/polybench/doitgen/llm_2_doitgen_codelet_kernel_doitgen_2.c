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
        // Reverse the order of p-loop to access sum and A in reverse index order
        for (p = np - 1; p >= 0; p--) {
            sum[p] = 0.;
            for (s = 0; s < np; s++)
                sum[p] += A[r][q][s] * C4[s][p];
        }
        for (p = np - 1; p >= 0; p--)
            A[r][q][p] = sum[p];
    }
}
