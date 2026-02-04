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
for (i = 0; i < m; i++)
    for (k = i + 1; k < m; k++)
        for (j = 0; j < n; j++) {
            B[i][j] += A[k][i] * B[k][j];
            if (k == m - 1) // Only apply scaling once per (i,j), after all k
                B[i][j] = alpha * B[i][j];
        }
}
