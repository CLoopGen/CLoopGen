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
    }
    for (k = 0; k < nk; k++) {
        double temp_alpha_Aik = alpha * A[i][k];
        for (j = 0; j < nj; j += 4) {
            if (j + 0 < nj) C[i][j + 0] += temp_alpha_Aik * B[k][j + 0];
            if (j + 1 < nj) C[i][j + 1] += temp_alpha_Aik * B[k][j + 1];
            if (j + 2 < nj) C[i][j + 2] += temp_alpha_Aik * B[k][j + 2];
            if (j + 3 < nj) C[i][j + 3] += temp_alpha_Aik * B[k][j + 3];
        }
    }
}
}
