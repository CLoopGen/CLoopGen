#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000];
extern double B[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i++) {
        A[i] = A[i-1] + (1.0 / n);
        B[i] = B[i-1] + (1.0 / n);
    }
    if (n > 0) {
        A[0] = 2.0 / n;
        B[0] = 3.0 / n;
    }
}
