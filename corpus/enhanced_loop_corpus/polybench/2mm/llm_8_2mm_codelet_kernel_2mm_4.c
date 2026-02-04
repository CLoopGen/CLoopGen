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
for (i = 0; i < ni; i++)
    for (j = 0; j < nj; j++) {
        tmp[i][j] = 0.;
        for (k = 0; k < nk; ++k) {
            double product = alpha * A[i][k] * B[k][j];
            tmp[i][j] += product;
            tmp[i][j] += product * 0.1;  // Increased arithmetic operations per iteration
        }
    }
}
