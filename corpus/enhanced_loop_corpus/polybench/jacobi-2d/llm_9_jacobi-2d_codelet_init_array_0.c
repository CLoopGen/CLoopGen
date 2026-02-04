#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[1300][1300];
extern double B[1300][1300];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2)
    for (j = 0; j < n; j += 2) {
        double coeff_i = (double)i / n;
        A[i][j] = coeff_i * (j + 2) + 2.0 / n;
        B[i][j] = coeff_i * (j + 3) + 3.0 / n;
        
        if (i + 1 < n) {
            A[i+1][j] = ((double)(i+1) * (j + 2) + 2) / n;
            B[i+1][j] = ((double)(i+1) * (j + 3) + 3) / n;
        }
        if (j + 1 < n) {
            A[i][j+1] = ((double)i * (j+1 + 2) + 2) / n;
            B[i][j+1] = ((double)i * (j+1 + 3) + 3) / n;
        }
        if (i + 1 < n && j + 1 < n) {
            A[i+1][j+1] = ((double)(i+1) * (j+1 + 2) + 2) / n;
            B[i+1][j+1] = ((double)(i+1) * (j+1 + 3) + 3) / n;
        }
    }
}
