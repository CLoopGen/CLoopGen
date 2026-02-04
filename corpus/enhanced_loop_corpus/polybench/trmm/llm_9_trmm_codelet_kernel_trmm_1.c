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
for (i = 0; i < m && i < 500; i++)
    for (j = 0; j < n; j++) {
        double sum1 = 0.0, sum2 = 0.0;
        int k_start = i + 1;
        for (k = k_start; k < m; k++) {
            sum1 += A[k][i] * B[k][j];
            if (k + 32 < m) {
                sum2 += A[k+32][i] * B[k+32][j];
            }
        }
        B[i][j] = alpha * (B[i][j] + sum1 + sum2);
    }
}
