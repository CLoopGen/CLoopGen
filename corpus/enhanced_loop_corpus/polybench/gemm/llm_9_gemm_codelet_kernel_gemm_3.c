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
for (i = 0; i < ni; i += 2) {
    for (j = 0; j < nj; j += 2) {
        if (i < ni) C[i][j] *= beta;
        if (i < ni && j + 1 < nj) C[i][j+1] *= beta;
        if (i + 1 < ni && j < nj) C[i+1][j] *= beta;
        if (i + 1 < ni && j + 1 < nj) C[i+1][j+1] *= beta;
    }
    for (k = 0; k < nk; k++) {
        for (j = 0; j < nj; j++) {
            if (i < ni) C[i][j] += alpha * A[i][k] * B[k][j];
            if (i + 1 < ni) C[i+1][j] += alpha * A[i+1][k] * B[k][j];
        }
    }
}
}
