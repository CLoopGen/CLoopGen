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
        for (i = 1; i <= n - 2; i++)
            for (j = 1; j <= n - 2; j += 2) {
                double temp1 = (A[i - 1][j - 1] + A[i - 1][j] + A[i - 1][j + 1] +
                                A[i][j - 1] + A[i][j] + A[i][j + 1] +
                                A[i + 1][j - 1] + A[i + 1][j] + A[i + 1][j + 1]) / 9.;
                if (j + 1 <= n - 2) {
                    double temp2 = (A[i - 1][j] + A[i - 1][j + 1] + A[i - 1][j + 2] +
                                    A[i][j] + A[i][j + 1] + A[i][j + 2] +
                                    A[i + 1][j] + A[i + 1][j + 1] + A[i + 1][j + 2]) / 9.;
                    A[i][j] = temp1;
                    A[i][j + 1] = temp2;
                } else {
                    A[i][j] = temp1;
                }
            }
}
