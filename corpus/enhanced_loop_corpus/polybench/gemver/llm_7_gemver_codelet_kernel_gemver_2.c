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
    for (j = 0; j < n; j++) {
        double beta_yj = beta * y[j];
        for (i = 0; i < n; i++) {
            x[i] = x[i] + beta_yj * A[j][i];
        }
    }
}
