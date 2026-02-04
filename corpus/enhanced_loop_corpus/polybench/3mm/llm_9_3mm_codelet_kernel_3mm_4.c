#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nj;
extern int nk;
extern double E[800][900];
extern double A[800][1000];
extern double B[1000][900];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni && i < 500; i++)
    for (j = 0; j < nj && j < 600; j++) {
        double sum1 = 0.0, sum2 = 0.0;
        int ki;
        for (ki = 0; ki < nk; ki += 2) {
            if (ki + 1 < nk) {
                sum1 += A[i][ki] * B[ki][j];
                sum2 += A[i][ki+1] * B[ki+1][j];
            } else {
                sum1 += A[i][ki] * B[ki][j];
            }
        }
        E[i][j] = sum1 + sum2;
    }
}
