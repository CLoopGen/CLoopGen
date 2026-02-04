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
for (t = 1; t <= 1000; t += 2) {
    for (i = 1; i < n - 1; i += 2) {
        for (j = 1; j < n - 1; j += 2) {
            for (k = 1; k < n - 1; k += 2) {
                double laplacian = 6.0 * A[i][j][k];
                laplacian -= (A[i + 1][j][k] + A[i - 1][j][k] +
                             A[i][j + 1][k] + A[i][j - 1][k] +
                             A[i][j][k + 1] + A[i][j][k - 1]);
                B[i][j][k] = A[i][j][k] - 0.125 * laplacian;
            }
        }
    }
    for (i = 1; i < n - 1; i += 2) {
        for (j = 1; j < n - 1; j += 2) {
            for (k = 1; k < n - 1; k += 2) {
                double laplacian = 6.0 * B[i][j][k];
                laplacian -= (B[i + 1][j][k] + B[i - 1][j][k] +
                             B[i][j + 1][k] + B[i][j - 1][k] +
                             B[i][j][k + 1] + B[i][j][k - 1]);
                A[i][j][k] = B[i][j][k] - 0.125 * laplacian;
            }
        }
    }
}
}
