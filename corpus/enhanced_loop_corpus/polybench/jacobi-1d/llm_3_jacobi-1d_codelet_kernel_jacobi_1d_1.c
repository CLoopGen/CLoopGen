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
    for (i = 2; i < n - 1; i += 2) {
        int j = i;
        B[j] = 0.33333000000000002 * (A[j - 1] + A[j] + A[j + 1]);
    }
    for (i = 2; i < n - 1; i += 2) {
        int j = i;
        A[j] = 0.33333000000000002 * (B[j - 1] + B[j] + B[j + 1]);
    }
}
}
