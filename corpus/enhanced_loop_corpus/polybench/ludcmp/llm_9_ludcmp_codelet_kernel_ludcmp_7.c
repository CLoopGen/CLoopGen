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
        for (j = i + 1; j < n; j += 2) {
            if (j + 1 < n) {
                w -= A[i][j] * x[j] + A[i][j+1] * x[j+1];
            } else {
                w -= A[i][j] * x[j];
            }
        }
        x[i] = w / A[i][i];
    }
}
