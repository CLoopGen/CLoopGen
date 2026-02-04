#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double beta;
extern double A[2000][2000];
extern double x[2000];
extern double y[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    double xi_temp = 0.0;
    for (j = 0; j < n; j++) {
        if (y[j] == 0.0) continue;  // Skip iteration if y[j] is zero
        xi_temp += beta * A[j][i] * y[j];
    }
    x[i] += xi_temp;  // Update x[i] once per i
}
}
