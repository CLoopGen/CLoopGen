#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nj;
extern int nk;
extern double alpha;
extern double beta;
extern double C[1000][1100];
extern double A[1000][1200];
extern double B[1200][1100];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni; i++) {
    for (j = 0; j < nj; j++) {
        C[i][j] *= beta;
        for (k = 0; k < nk; k++) {
            C[i][j] += alpha * A[i][k] * B[k][j];
        }
    }
}
}
