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
// Introduce loop-carried dependence via scalar variable and reorder computations
double temp = 0.0;
for (i = 0; i < n; i++) {
    // Create RAW dependence: each iteration depends on previous temp value
    u1[i] = temp;
    temp = ((i + 1) / fn) / 2.;

    u2[i] = ((i + 1) / fn) / 2.;
    v1[i] = ((i + 1) / fn) / 4.;
    v2[i] = ((i + 1) / fn) / 6.;
    y[i] = ((i + 1) / fn) / 8.;
    z[i] = ((i + 1) / fn) / 9.;
    x[i] = 0.;
    w[i] = 0.;
    // Eliminate inner loop parallelism by introducing loop-carried flow dependence
    for (j = i; j < n; j++) {  // WAR dependence due to index overlap in writes
        if (j > i) {
            A[i][j] = A[j-1][i] + (double)(i * j % n) / n; // RAW: use of A[j-1][i]
        } else {
            A[i][j] = (double)(i * j % n) / n;
        }
    }
}
}
