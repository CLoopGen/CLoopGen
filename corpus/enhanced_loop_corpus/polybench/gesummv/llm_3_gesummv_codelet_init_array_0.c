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
for (j = 0; j < n; j++) {
    for (i = 0; i < n; i++) {
        A[i][j] = (double)((i * j + 1) % n) / n;  // Interchanged loops: j outer, i inner
        B[i][j] = (double)((i * j + 2) % n) / n;
    }
    x[j] = (double)(j % n) / n;  // Moved after inner loop, still computes same result
}
}
