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
int *idx = (int*)__builtin_alloca(m * sizeof(int));
for (i = 0; i < m; i++) idx[i] = i;
for (i = 0; i < m; i++) {
    int ii = idx[i];
    for (j = 0; j < ii; j++) {
        A[ii][j] = (double)((ii + j) % m) / m;
    }
    A[ii][ii] = 1.;
    for (j = 0; j < n; j++) {
        int jj = (j + i) % n;
        B[ii][jj] = (double)((n + (ii - jj)) % n) / n;
    }
}
}
