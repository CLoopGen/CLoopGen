#include <stdio.h>

#include <inttypes.h>

extern int tsteps;
extern int n;
extern double A[1300][1300];
extern double B[1300][1300];
extern int t;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (t = 0; t < tsteps; t++) {
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            double temp_B = 0.20000000000000001 * (A[i][j] + A[i][j - 1] + A[i][1 + j] + A[1 + i][j] + A[i - 1][j]);
            B[i][j] = temp_B;
            if (i > 1 && j > 1) { // Delayed update to A using values from previous B updates
                A[i-1][j-1] = 0.20000000000000001 * (B[i-1][j-1] + B[i-1][j-2] + B[i-1][j] + B[i][j-1] + B[i-2][j-1]);
            }
        }
    }
    // Finalize remaining A updates not covered in pipelined update
    for (j = 1; j < n - 1; j++) {
        A[n-2][j] = 0.20000000000000001 * (B[n-2][j] + B[n-2][j-1] + B[n-2][j+1] + B[n-1][j] + B[n-3][j]);
    }
    for (i = 1; i < n - 2; i++) {
        A[i][n-2] = 0.20000000000000001 * (B[i][n-2] + B[i][n-3] + B[i][n-1] + B[i+1][n-2] + B[i-1][n-2]);
    }
}
}
