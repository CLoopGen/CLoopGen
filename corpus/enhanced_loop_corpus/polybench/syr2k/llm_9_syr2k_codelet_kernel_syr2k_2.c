#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double alpha;
extern double beta;
extern double C[1200][1200];
extern double A[1200][1000];
extern double B[1200][1000];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) { // Increased loop stride to reduce outer loop iterations
    if (i + 1 < n) {
        for (j = 0; j <= i + 1; j++) {
            C[i][j] *= beta;
            C[i+1][j] *= beta;
        }
    } else {
        for (j = 0; j <= i; j++) {
            C[i][j] *= beta;
        }
    }
    for (k = 0; k < m; k++) {
        for (j = 0; j <= i; j++) {
            double a_jk = A[j][k], b_ik = B[i][k];
            double b_jk = B[j][k], a_ik = A[i][k];
            // Fused operations and reuse intermediates to increase computational density
            double term = alpha * (a_jk * b_ik + b_jk * a_ik);
            C[i][j] += term;
            if (i + 1 < n && j <= i + 1) {
                C[i+1][j] += A[j][k] * alpha * B[i+1][k] + B[j][k] * alpha * A[i+1][k];
            }
        }
    }
}
}
