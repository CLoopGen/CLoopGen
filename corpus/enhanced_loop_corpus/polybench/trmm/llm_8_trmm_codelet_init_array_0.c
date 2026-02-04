#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1000][1000];
extern double B[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i += 2) {
    for (j = 0; j < i; j += 2) {
        A[i][j] = (double)((i + j * 3) % m) / m;
        if (i + 1 < m) A[i+1][j] = (double)((i + 1 + j * 3) % m) / m;
        if (j + 1 < i) A[i][j+1] = (double)((i + (j+1) * 3) % m) / m;
        if (i + 1 < m && j + 1 < i + 1) A[i+1][j+1] = (double)((i + 1 + (j+1) * 3) % m) / m;
    }
    A[i][i] = 1.;
    if (i + 1 < m) A[i+1][i+1] = 1.;
    for (j = 0; j < n; j++) {
        B[i][j] = (double)((n + (i - j * 2)) % n) / n;
        if (i + 1 < m) B[i+1][j] = (double)((n + (i + 1 - j * 2)) % n) / n;
    }
}
}
