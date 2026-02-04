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
for (k = 0; k < n; k++)
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++)
            A[i][j][k] = B[i][j][k] = (double)(i + j + (n - k)) * 10 / (n);
}
