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
    int skip_beta = (beta == 1.0);
    for (j = 0; j < nj; j++) {
        if (!skip_beta) {
            C[i][j] *= beta;
        }
    }
    for (k = 0; k < nk; k++) {
        if (A[i][k] == 0.0) continue;
        double alpha_Aik = alpha * A[i][k];
        for (j = 0; j < nj; j++) {
            if (B[k][j] == 0.0) continue;
            C[i][j] += alpha_Aik * B[k][j];
        }
    }
}
}
