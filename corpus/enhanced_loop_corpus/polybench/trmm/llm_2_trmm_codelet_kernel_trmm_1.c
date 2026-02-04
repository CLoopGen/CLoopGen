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
    for (j = 0; j < n; j++) {
        double temp = B[i][j];
        for (k = i + 1; k < m; k++)
            temp += A[k][i] * B[k][j];
        B[i][j] = alpha * temp;
    }
}
