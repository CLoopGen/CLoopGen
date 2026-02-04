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
        if (beta != 1.0) {
            C[i][j] *= beta;
        }
    }
    for (k = 0; k < nk; k++) {
        if (alpha == 0.0) continue;
        for (j = 0; j < nj; j++) {
            double temp = A[i][k] * B[k][j];
            if (temp != 0.0) {
                C[i][j] += alpha * temp;
            }
        }
    }
}
}
