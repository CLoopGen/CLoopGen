#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nj;
extern int nl;
extern double beta;
extern double tmp[800][900];
extern double C[900][1200];
extern double D[800][1200];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++) {
        double sum1 = 0.0, sum2 = 0.0;
        D[i][j] *= beta;
        for (k = 0; k < nj - 1; k += 2) {
            sum1 += tmp[i][k] * C[k][j];
            sum2 += tmp[i][k+1] * C[k+1][j];
        }
        if (k < nj)
            sum1 += tmp[i][nj-1] * C[nj-1][j];
        D[i][j] += sum1 + sum2;
    }
}
