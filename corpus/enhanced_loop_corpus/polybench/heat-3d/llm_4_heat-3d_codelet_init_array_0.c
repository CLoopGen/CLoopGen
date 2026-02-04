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
                if (i % 2 == 0) {
                    A[i][j][k] = B[i][j][k] = (double)(i + j + (n - k)) * 10 / (n);
                } else {
                    A[i][j][k] = (double)(i + j) * 10 / n;
                    B[i][j][k] = (double)(j + (n - k)) * 10 / n;
                }
            }
}
