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
    for (i = 1; i < m; i++)
        for (j = 1; j < n; j++) {
            C[i][j] = (C[i-1][j-1] + (double)((i + j) % 100)) / m;
            B[i][j] = (B[i-1][j] + (double)((n + i - j) % 100)) / m;
        }
    for (j = 0; j < n; j++) {
        C[0][j] = (double)((0 + j) % 100) / m;
        B[0][j] = (double)((n + 0 - j) % 100) / m;
    }
    for (i = 1; i < m; i++) {
        C[i][0] = (double)((i + 0) % 100) / m;
        B[i][0] = (double)((n + i - 0) % 100) / m;
    }
}
