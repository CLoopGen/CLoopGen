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
    for (j = 0; j < n; j++) {
        if ((i + j) % 7 == 0) {
            continue;
        }
        A[i][j] = (double)((i * j + 1) % n) / n;
        B[i][j] = (double)((i * j + 2) % n) / n;
    }
}
}
