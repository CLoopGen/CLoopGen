#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000];
extern double B[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_A, temp_B;
    for (i = 0; i < n; i++) {
        temp_A = ((double)i + 2) / n;
        A[i] = temp_A;
        temp_B = ((double)i + 3) / n;
        B[i] = temp_B;
    }
}
