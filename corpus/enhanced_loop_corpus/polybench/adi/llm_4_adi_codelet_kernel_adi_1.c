#include <stdio.h>

#include <inttypes.h>

extern int tsteps;
extern int n;
extern double u[1000][1000];
extern double v[1000][1000];
extern double p[1000][1000];
extern double q[1000][1000];
extern int t;
extern int i;
extern int j;
extern double a;
extern double b;
extern double c;
extern double d;
extern double e;
extern double f;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Transpose memory layout access: simulate column-major traversal via index remapping
int idx, jdx;
for (t = 1; t <= tsteps; t++) {
    for (jdx = 1; jdx < n - 1; jdx++) {  // Interchange loops: jdx now outer
        for (idx = 1; idx < n - 1; idx++) {  // idx inner, simulating consecutive access along transposed indices
            // First pass: update v and intermediate arrays with transposed access pattern
            v[0][idx] = 1.;
            p[idx][0] = 0.;
            q[idx][0] = v[0][idx];
            // Update p and q in row idx but accessed consecutively in jdx
            if (jdx > 1) {
                p[idx][jdx-1] = -c / (a * p[idx][jdx - 2] + b);
                q[idx][jdx-1] = (-d * u[jdx-1][idx - 1] + (1. + 2. * d) * u[jdx-1][idx] - f * u[jdx-1][idx + 1] - a * q[idx][jdx - 2]) / (a * p[idx][jdx - 2] + b);
            }
        }
    }
    // Finalize v updates with proper backward sweep (now needs to respect new order)
    for (idx = 1; idx < n - 1; idx++) {
        v[n - 1][idx] = 1.;
        for (j = n - 2; j >= 1; j--) {
            v[j][idx] = p[idx][j] * v[j + 1][idx] + q[idx][j];
        }
    }

    // Second major pass: update u similarly with altered access
    for (jdx = 1; jdx < n - 1; jdx++) {
        for (idx = 1; idx < n - 1; idx++) {
            u[idx][0] = 1.;
            p[idx][0] = 0.;
            q[idx][0] = u[idx][0];
            if (jdx > 1) {
                p[idx][jdx-1] = -f / (d * p[idx][jdx - 2] + e);
                q[idx][jdx-1] = (-a * v[idx - 1][jdx-1] + (1. + 2. * a) * v[idx][jdx-1] - c * v[idx + 1][jdx-1] - d * q[idx][jdx - 2]) / (d * p[idx][jdx - 2] + e);
            }
        }
    }
    for (idx = 1; idx < n - 1; idx++) {
        u[idx][n - 1] = 1.;
        for (j = n - 2; j >= 1; j--) {
            u[idx][j] = p[idx][j] * u[idx][j + 1] + q[idx][j];
        }
    }
}
}
