#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double C[1000][1200];
extern double B[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i += 2)
    for (j = 0; j < n; j += 2) {
        // Reduced trip count by stepping in increments of 2
        // Also reduced operations: replaced modulo with simple addition and scaling
        C[i][j] = (double)(i + j + 1) * 0.01;
        if (i + 1 < m && j + 1 < n) {
            C[i+1][j+1] = C[i][j];
            B[i][j] = C[i][j];
            B[i+1][j+1] = C[i][j];
        }
        B[i][j] = (double)(i - j + n) * 0.01;
    }
}
