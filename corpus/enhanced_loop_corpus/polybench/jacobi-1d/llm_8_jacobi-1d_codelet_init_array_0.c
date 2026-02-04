#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000];
extern double B[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            A[i] = ((double)i + 2) / n;
            A[i+1] = ((double)(i+1) + 2) / n;
            B[i] = ((double)i + 3) / n;
            B[i+1] = ((double)(i+1) + 3) / n;
        } else {
            A[i] = ((double)i + 2) / n;
            B[i] = ((double)i + 3) / n;
        }
    }
}
