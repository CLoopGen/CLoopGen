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
for (k = 0; k < nj; k++)
    for (i = 0; i < ni; i++) {
        double factor = tmp[i][k];
        for (j = 0; j < nl; j++)
            D[i][j] += factor * C[k][j];
    }
for (i = 0; i < ni; i++)
    for (j = 0; j < nl; j++)
        D[i][j] *= beta;
}
