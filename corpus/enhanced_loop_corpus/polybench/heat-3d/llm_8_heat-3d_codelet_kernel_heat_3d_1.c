#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[120][120][120];
extern double B[120][120][120];
extern int t;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (t = 1; t <= 250; t++) {
    for (i = 2; i < n - 2; i++) {
        for (j = 2; j < n - 2; j++) {
            for (k = 2; k < n - 2; k++) {
                double temp_ax = 0.125 * (A[i + 1][j][k] - 2. * A[i][j][k] + A[i - 1][j][k]);
                double temp_ay = 0.125 * (A[i][j + 1][k] - 2. * A[i][j][k] + A[i][j - 1][k]);
                double temp_az = 0.125 * (A[i][j][k + 1] - 2. * A[i][j][k] + A[i][j][k - 1]);
                B[i][j][k] = temp_ax + temp_ay + temp_az + A[i][j][k];
            }
        }
    }
    for (i = 2; i < n - 2; i++) {
        for (j = 2; j < n - 2; j++) {
            for (k = 2; k < n - 2; k++) {
                double temp_bx = 0.125 * (B[i + 1][j][k] - 2. * B[i][j][k] + B[i - 1][j][k]);
                double temp_by = 0.125 * (B[i][j + 1][k] - 2. * B[i][j][k] + B[i][j - 1][k]);
                double temp_bz = 0.125 * (B[i][j][k + 1] - 2. * B[i][j][k] + B[i][j][k - 1]);
                A[i][j][k] = temp_bx + temp_by + temp_bz + B[i][j][k];
            }
        }
    }
}
}
