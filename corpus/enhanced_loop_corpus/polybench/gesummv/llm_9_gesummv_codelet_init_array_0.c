#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[1300][1300];
extern double B[1300][1300];
extern double x[1300];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    if (i + 1 < n) {
        x[i] = (double)(i % n) / n;
        x[i+1] = (double)((i+1) % n) / n;
        for (j = 0; j < n; j++) {
            A[i][j] = (double)((i * j + 1) % n) / n;
            A[i+1][j] = (double)(((i+1) * j + 1) % n) / n;
            B[i][j] = (double)((i * j + 2) % n) / n;
            B[i+1][j] = (double)(((i+1) * j + 2) % n) / n;
        }
    } else {
        x[i] = (double)(i % n) / n;
        for (j = 0; j < n; j++) {
            A[i][j] = (double)((i * j + 1) % n) / n;
            B[i][j] = (double)((i * j + 2) % n) / n;
        }
    }
}
}
