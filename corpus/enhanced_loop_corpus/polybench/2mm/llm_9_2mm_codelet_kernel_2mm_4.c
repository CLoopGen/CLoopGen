#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nj;
extern int nk;
extern double alpha;
extern double tmp[800][900];
extern double A[800][1100];
extern double B[1100][900];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i += 2)
    for (j = 0; j < nj; j += 2)
        for (k = 0; k < nk; ++k) {
            double a1 = alpha * A[i][k];
            double a2 = (i+1 < ni) ? alpha * A[i+1][k] : 0.0;
            double b1 = B[k][j];
            double b2 = (j+1 < nj) ? B[k][j+1] : 0.0;

            tmp[i][j] += a1 * b1;
            if (i+1 < ni) tmp[i+1][j] += a2 * b1;
            if (j+1 < nj) tmp[i][j+1] += a1 * b2;
            if (i+1 < ni && j+1 < nj) tmp[i+1][j+1] += a2 * b2;
        }
}
