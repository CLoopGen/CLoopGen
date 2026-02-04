#include <stdio.h>

#include <inttypes.h>

extern int tsteps;
extern int n;
extern double A[2000][2000];
extern int t;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (t = 0; t <= tsteps - 1; t++)
    for (i = 2; i <= n - 3; i++)
        for (j = 2; j <= n - 3; j++)
            A[i][j] = (A[i - 2][j - 2] + A[i - 2][j] + A[i - 2][j + 2] + 
                       A[i][j - 2] + A[i][j] + A[i][j + 2] + 
                       A[i + 2][j - 2] + A[i + 2][j] + A[i + 2][j + 2]) / 9.;
}
