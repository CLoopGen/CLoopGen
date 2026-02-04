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
for (i = 1; i < n; i++)
    for (j = 1; j < m; j++) {
        A[i][j] = A[i-1][j-1] + (double)((i * j + 1) % n) / n;
        B[i][j] = (double)((i * j + 2) % m) / m;
    }
for (j = 0; j < m; j++) {
    A[0][j] = (double)((0 * j + 1) % n) / n;
    B[0][j] = (double)((0 * j + 2) % m) / m;
}
for (i = 1; i < n; i++) {
    A[i][0] = A[i-1][0] + (double)((i * 0 + 1) % n) / n;
    B[i][0] = (double)((i * 0 + 2) % m) / m;
}
}
