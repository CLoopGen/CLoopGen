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
for (t = 0; t <= tsteps - 1; t += 2)
    for (i = 1; i <= n - 2; i++)
        for (j = 1; j <= n - 2; j += 2)
            A[i][j] = (A[i - 1][j - 1] + A[i - 1][j] + A[i - 1][j + 1] + 
                       A[i][j - 1] + A[i][j] + A[i][j + 1] + 
                       A[i + 1][j - 1] + A[i + 1][j] + A[i + 1][j + 1]) / 9.;

    for (t = 1; t <= tsteps - 1; t += 2)
        for (i = 1; i <= n - 2; i++)
            for (j = 2; j <= n - 3; j++)
                A[i][j] = (A[i-1][j] + A[i][j-1] + A[i][j] + A[i][j+1] + A[i+1][j]) / 5.;
}
