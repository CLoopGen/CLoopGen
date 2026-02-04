#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double alpha;
extern double beta;
extern double C[1000][1200];
extern double A[1000][1000];
extern double B[1000][1200];
extern int i;
extern int j;
extern int k;
extern double temp2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
        temp2 = 0;
        for (k = 0; k < i; k += 2) {
            if (k + 1 < i) {
                C[k][j] += alpha * B[i][j] * A[i][k];
                C[k+1][j] += alpha * B[i][j] * A[i][k+1];
                temp2 += B[k][j] * A[i][k] + B[k+1][j] * A[i][k+1];
            } else {
                C[k][j] += alpha * B[i][j] * A[i][k];
                temp2 += B[k][j] * A[i][k];
            }
        }
        C[i][j] = beta * C[i][j] + alpha * B[i][j] * A[i][i] + alpha * temp2;
    }
}
