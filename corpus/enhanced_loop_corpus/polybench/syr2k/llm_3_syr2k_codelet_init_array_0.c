#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int m;
extern double A[1200][1000];
extern double B[1200][1000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2)
    for (j = 0; j < m; j += 2) {
        A[i][j] = (double)((i * j + 1) % n) / n;
        B[i][j] = (double)((i * j + 2) % m) / m;
        if (i + 1 < n) {
            A[i+1][j] = (double)(((i+1) * j + 1) % n) / n;
            B[i+1][j] = (double)(((i+1) * j + 2) % m) / m;
        }
        if (j + 1 < m) {
            A[i][j+1] = (double)((i * (j+1) + 1) % n) / n;
            B[i][j+1] = (double)((i * (j+1) + 2) % m) / m;
        }
        if (i + 1 < n && j + 1 < m) {
            A[i+1][j+1] = (double)(((i+1) * (j+1) + 1) % n) / n;
            B[i+1][j+1] = (double)(((i+1) * (j+1) + 2) % m) / m;
        }
    }
}
