#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double A[1000][1200];
extern double Q[1000][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    A[i][0] = (((double)((i * 0) % m) / m) * 100) + 10;
    Q[i][0] = 0.;
    for (j = 1; j < n; j++) {
        A[i][j] = (((double)((i * j) % m) / m) * 100) + 10;
        Q[i][j] = 0.;
    }
}
}
