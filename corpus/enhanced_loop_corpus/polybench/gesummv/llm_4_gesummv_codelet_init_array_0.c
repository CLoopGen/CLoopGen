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
    if (i % 2 == 0) {
        x[i] = (double)(i % n) / n;
    } else {
        x[i] = 0.0;
    }
    for (j = 0; j < n; j++) {
        if ((i * j) % 3 == 0) {
            A[i][j] = (double)((i * j + 1) % n) / n;
            B[i][j] = (double)((i * j + 2) % n) / n;
        } else {
            A[i][j] = 0.0;
            B[i][j] = 0.0;
        }
    }
}
}
