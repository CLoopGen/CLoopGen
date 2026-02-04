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
            double temp_B = 0.20000000000000001 * (A[i][j] + A[i][j - 1] + A[i][j + 1] + A[i + 1][j] + A[i - 1][j]);
            B[i][j] = temp_B;
        }
    }
    // Introduce artificial loop-carried dependence by splitting update and using a scalar
    double prev_A_update = 0.0;
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            double temp_val = 0.20000000000000001 * (B[i][j] + B[i][j - 1] + B[i][j + 1] + B[i + 1][j] + B[i - 1][j]);
            // Create a WAW and RAW dependency across iterations via prev_A_update
            temp_val += prev_A_update * 0.1;
            A[i][j] = temp_val;
            prev_A_update = temp_val; // Loop-carried flow dependence introduced
        }
    }
}
}
