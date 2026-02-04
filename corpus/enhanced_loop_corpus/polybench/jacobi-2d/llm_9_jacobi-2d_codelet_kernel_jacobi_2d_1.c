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
for (t = 0; t < tsteps; t += 2) {
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            double temp1 = 0.2 * (A[i][j] + A[i][j-1] + A[i][j+1] + A[i-1][j] + A[i+1][j]);
            B[i][j] = temp1;
        }
    }
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            double temp2 = 0.2 * (B[i][j] + B[i][j-1] + B[i][j+1] + B[i-1][j] + B[i+1][j]);
            A[i][j] = temp2;
        }
    }
    if (t + 1 < tsteps) {
        for (i = 1; i < n - 1; i++) {
            for (j = 1; j < n - 1; j++) {
                double temp1 = 0.2 * (A[i][j] + A[i][j-1] + A[i][j+1] + A[i-1][j] + A[i+1][j]);
                B[i][j] = temp1;
            }
        }
        for (i = 1; i < n - 1; i++) {
            for (j = 1; j < n - 1; j++) {
                double temp2 = 0.2 * (B[i][j] + B[i][j-1] + B[i][j+1] + B[i-1][j] + B[i+1][j]);
                A[i][j] = temp2;
            }
        }
    }
}
}
