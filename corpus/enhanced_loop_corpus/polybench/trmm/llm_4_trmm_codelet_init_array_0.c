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
        if ((i + j) % 2 == 0) {
            A[i][j] = (double)((i + j) % m) / m;
        } else {
            continue;
        }
    }
    A[i][i] = 1.;
    for (j = 0; j < n; j++) {
        if (i >= j) {
            B[i][j] = (double)((n + (i - j)) % n) / n;
        }
    }
}
}
