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
for (i = 0; i < n; i += 2) {
    for (j = 0; j < n; j++) {
        if (i + 1 < n) {
            x[i]   += beta * A[j][i]     * y[j];
            x[i+1] += beta * A[j][i+1]   * y[j];
        } else {
            x[i] += beta * A[j][i] * y[j];
        }
    }
}
}
