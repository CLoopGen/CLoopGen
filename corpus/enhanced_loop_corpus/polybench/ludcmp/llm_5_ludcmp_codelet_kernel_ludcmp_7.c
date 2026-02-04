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
    for (i = n - 1; i >= 0; i--) {
        w = y[i];
        for (j = i + 1; j < n; j++) {
            if (x[j] == 0.0) {
                continue;
            }
            w -= A[i][j] * x[j];
        }
        if (A[i][i] != 0.0) {
            x[i] = w / A[i][i];
        } else {
            x[i] = w;
        }
    }
}
