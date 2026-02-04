#include <stdio.h>

#include <inttypes.h>

extern int tsteps;
extern int n;
extern double A[1300][1300];
extern double B[1300][1300];
extern int t;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (t = 0; t < tsteps; t++) {
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            if (A[i][j] < 0.0) continue;
            B[i][j] = 0.20000000000000001 * (A[i][j] + A[i][j - 1] + A[i][1 + j] + A[1 + i][j] + A[i - 1][j]);
        }
    }
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            if (B[i][j] < 0.0) continue;
            A[i][j] = 0.20000000000000001 * (B[i][j] + B[i][j - 1] + B[i][1 + j] + B[1 + i][j] + B[i - 1][j]);
        }
    }
}
}
