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
for (i = 0; i < n; i++) {
    x[i] = (double)(i % n) / n;
    for (j = 0; j < n; j += 2) {
        if (j + 1 < n) {
            A[i][j] = (double)((i * j + 1) % n) / n;
            A[i][j+1] = (double)((i * (j+1) + 1) % n) / n;
            B[i][j] = (double)((i * j + 2) % n) / n;
            B[i][j+1] = (double)((i * (j+1) + 2) % n) / n;
        } else {
            A[i][j] = (double)((i * j + 1) % n) / n;
            B[i][j] = (double)((i * j + 2) % n) / n;
        }
    }
}
}
