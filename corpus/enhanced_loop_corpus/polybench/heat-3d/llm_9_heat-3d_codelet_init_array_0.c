#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double A[120][120][120];
extern double B[120][120][120];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        for (k = 0; k < n; k++) {
            double temp = (double)(i * j + j * k + k * i) * 20.0 / (n * n);
            A[i][j][k] = temp + 1.5;
            B[i][j][k] = temp - 1.5;
        }
}
