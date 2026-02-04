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
    for (j = 0; j < n; j++)
        for (k = i + 1; k < m; k++) {
            B[i][j] += A[k][i] * B[k][j];
            if (k == m - 1) // Final iteration of k
                B[i][j] = alpha * B[i][j];
        }
}
