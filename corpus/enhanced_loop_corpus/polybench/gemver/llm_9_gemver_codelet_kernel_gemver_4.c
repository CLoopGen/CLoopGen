#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double alpha;
extern double A[2000][2000];
extern double w[2000];
extern double x[2000];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    for (j = 0; j < n; j += 2) {
        if (i + 1 < n) {
            w[i]   += alpha * A[i][j] * x[j];
            w[i+1] += alpha * A[i+1][j] * x[j];
        } else if (i < n) {
            w[i] += alpha * A[i][j] * x[j];
        }
    }
}
}
