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
for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
        if (beta != 1.0) {
            C[i][j] *= beta;
        }
    }
    for (k = 0; k < m; k++) {
        for (j = 0; j <= i; j++) {
            double temp1 = A[j][k] * alpha * B[i][k];
            double temp2 = B[j][k] * alpha * A[i][k];
            if (temp1 != 0.0 || temp2 != 0.0) {
                C[i][j] += temp1 + temp2;
            }
        }
    }
}
}
