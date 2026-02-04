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
for (j = 0; j < n; j++)
    for (i = 0; i < m; i++) {
        temp2 = 0;
        for (k = 0; k < i; k++) {
            // Transposed loop order (j-i-k) with consecutive access pattern in inner loop for improved cache performance on B and C
            C[k][j] += alpha * B[i][j] * A[i][k];
            temp2 += B[k][j] * A[i][k];
        }
        C[i][j] = beta * C[i][j] + alpha * B[i][j] * A[i][i] + alpha * temp2;
    }
}
