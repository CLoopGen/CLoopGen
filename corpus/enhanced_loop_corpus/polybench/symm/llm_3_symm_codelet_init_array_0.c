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
        C[i][j] = (double)((i + j) % 100) / m;
        B[i][j] = (double)((n + i - j) % 100) / m;
        if (i + 1 < m) {
            C[i+1][j] = (double)(((i+1) + j) % 100) / m;
            B[i+1][j] = (double)((n + (i+1) - j) % 100) / m;
        }
        if (j + 1 < n) {
            C[i][j+1] = (double)((i + (j+1)) % 100) / m;
            B[i][j+1] = (double)((n + i - (j+1)) % 100) / m;
        }
        if (i + 1 < m && j + 1 < n) {
            C[i+1][j+1] = (double)(((i+1) + (j+1)) % 100) / m;
            B[i+1][j+1] = (double)((n + (i+1) - (j+1)) % 100) / m;
        }
    }
}
