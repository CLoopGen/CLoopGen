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
for (i = 0; i < m; i++) {
    for (j = 0; j < i; j++) {
        A[i][j] = (double)((i + j) % m) / m;
    }
    A[i][i] = 1.;
    for (j = n - 1; j >= 0; j--) {
        B[i][j] = (double)((n + (i - j)) % n) / n;
    }
}
}
