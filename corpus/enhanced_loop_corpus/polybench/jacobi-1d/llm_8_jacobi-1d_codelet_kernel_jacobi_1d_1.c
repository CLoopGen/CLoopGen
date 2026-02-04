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
    for (i = 2; i < n - 2; i++) {
        B[i] = 0.25 * (A[i-2] + A[i-1] + A[i] + A[i+1] + A[i+2]);
    }
    for (i = 2; i < n - 2; i++) {
        A[i] = 0.2 * (B[i-2] + B[i-1] + B[i] + B[i+1] + B[i+2]);
    }
}
}
