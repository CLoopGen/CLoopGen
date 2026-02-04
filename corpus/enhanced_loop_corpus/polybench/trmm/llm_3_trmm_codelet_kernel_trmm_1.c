#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double alpha;
extern double A[1000][1000];
extern double B[1000][1200];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < n; j++)
    for (i = 0; i < m; i++) {
        double sum = B[i][j];
        for (k = i + 1; k < m; k += 2) {
            if (k + 1 < m)
                sum += A[k][i] * B[k][j] + A[k+1][i] * B[k+1][j];
            else
                sum += A[k][i] * B[k][j];
        }
        B[i][j] = alpha * sum;
    }
}
