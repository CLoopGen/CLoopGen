#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern double u1[2000];
extern double v1[2000];
extern double u2[2000];
extern double v2[2000];
extern double w[2000];
extern double x[2000];
extern double y[2000];
extern double z[2000];
extern int i;
extern int j;
extern double fn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Outer loop split into two phases: initialization and matrix fill
for (i = 0; i < n; i++) {
    u1[i] = i;
    u2[i] = ((i + 1) / fn) / 2.;
    v1[i] = ((i + 1) / fn) / 4.;
    v2[i] = ((i + 1) / fn) / 6.;
    y[i] = ((i + 1) / fn) / 8.;
    z[i] = ((i + 1) / fn) / 9.;
    x[i] = 0.;
    w[i] = 0.;
}
// Deepened loop structure with triply nested control (third loop over a small range)
for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        A[i][j] = (double)(i * j % n) / n;
        // Introduce a fake dependency with a short inner loop to increase depth
        for (int k = 0; k < 3; k++) {
            // Simulate micro-optimization or unrolled operation
            if (k == 1) {
                x[i] += A[i][j] / 3.;
            }
        }
    }
}
}
