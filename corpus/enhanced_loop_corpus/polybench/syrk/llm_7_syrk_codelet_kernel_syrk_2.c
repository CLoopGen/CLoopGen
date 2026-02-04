#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double alpha;
extern double beta;
extern double C[1200][1200];
extern double A[1200][1000];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    for (j = 0; j <= i; j++) {
        double sum = C[i][j] * beta;
        for (k = 0; k < m; k++)
            sum += alpha * A[i][k] * A[j][k];
        C[i][j] = sum;
    }
}
}
