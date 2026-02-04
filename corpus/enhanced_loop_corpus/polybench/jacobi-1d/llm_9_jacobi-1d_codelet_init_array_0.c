#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000];
extern double B[2000];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        double idx = (double)i;
        double temp1 = idx + 2.0;
        double temp2 = idx + 3.0;
        double inv_n = 1.0 / n;
        A[i] = temp1 * inv_n;
        B[i] = temp2 * inv_n;
        
        // Additional computational work to increase intensity
        A[i] = (A[i] * A[i] + B[i]) / (A[i] + 1.0);
        B[i] = (B[i] * B[i] + A[i]) / (B[i] + 1.0);
    }
}
