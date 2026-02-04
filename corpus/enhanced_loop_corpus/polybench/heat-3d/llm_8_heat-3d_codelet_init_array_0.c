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
        for (k = 0; k < n; k += 2) {
            double val1 = (double)(i + j + (n - k)) * 10 / (n);
            A[i][j][k] = B[i][j][k] = val1;
            if (k + 1 < n) {
                double val2 = (double)(i + j + (n - (k + 1))) * 10 / (n);
                A[i][j][k+1] = B[i][j][k+1] = val2;
            }
        }
}
