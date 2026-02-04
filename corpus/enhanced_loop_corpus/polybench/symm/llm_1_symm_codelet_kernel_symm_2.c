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
    for (k = 0; k < i; k++)
        for (j = 0; j < n; j++) {
            C[k][j] += alpha * B[i][j] * A[i][k];
        }
for (i = 0; i < m; i++)
    for (j = 0; j < n; j++) {
        temp2 = 0;
        for (k = 0; k < i; k++) {
            temp2 += B[k][j] * A[i][k];
        }
        C[i][j] = beta * C[i][j] + alpha * B[i][j] * A[i][i] + alpha * temp2;
    }

}
