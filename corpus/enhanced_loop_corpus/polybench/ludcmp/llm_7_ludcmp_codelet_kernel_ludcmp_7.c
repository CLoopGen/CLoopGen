#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[2000][2000];
extern double x[2000];
extern double y[2000];
extern int i;
extern int j;
extern double w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double w_cache[2000];
    for (i = n - 1; i >= 0; i--) {
        w_cache[i] = y[i];
        for (j = i + 1; j < n; j++) {
            w_cache[i] -= A[i][j] * x[j];
        }
    }
    for (i = n - 1; i >= 0; i--) {
        x[i] = w_cache[i] / A[i][i];
    }
}
