#include <stdio.h>

#include <inttypes.h>

extern int tsteps;
extern int n;
extern double A[1300][1300];
extern double B[1300][1300];
extern int t;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (t = 0; t < tsteps; t++) {
    for (i = 2; i < n - 2; i++)
        for (j = 2; j < n - 2; j++)
            B[i][j] = 0.16666666666666666 * (A[i][j] + A[i][j-1] + A[i][j+1] + A[i-1][j] + A[i+1][j] + A[i-1][j-1] + A[i+1][j+1]);
    for (i = 2; i < n - 2; i++)
        for (j = 2; j < n - 2; j++)
            A[i][j] = 0.16666666666666666 * (B[i][j] + B[i][j-1] + B[i][j+1] + B[i-1][j] + B[i+1][j] + B[i-1][j-1] + B[i+1][j+1]);
}
}
