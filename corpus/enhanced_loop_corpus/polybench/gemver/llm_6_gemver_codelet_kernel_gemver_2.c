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
    double temp[2000] = {0.0};
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            temp[i] += beta * A[j][i] * y[j];
        }
    }
    for (i = 0; i < n; i++) {
        x[i] = x[i] + temp[i];
    }
}
