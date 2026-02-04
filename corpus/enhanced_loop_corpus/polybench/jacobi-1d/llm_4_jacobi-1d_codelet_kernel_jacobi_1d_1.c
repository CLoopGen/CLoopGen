#include <stdio.h>

#include <inttypes.h>

extern int tsteps;
extern int n;
extern double A[2000];
extern double B[2000];
extern int t;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (t = 0; t < tsteps; t++) {
    for (i = 1; i < n - 1; i++) {
        if (A[i] >= 0) {
            B[i] = 0.33333000000000002 * (A[i - 1] + A[i] + A[i + 1]);
        } else {
            B[i] = A[i];
        }
    }
    for (i = 1; i < n - 1; i++) {
        if (B[i] < 0) {
            continue;
        }
        A[i] = 0.33333000000000002 * (B[i - 1] + B[i] + B[i + 1]);
    }
}
}
