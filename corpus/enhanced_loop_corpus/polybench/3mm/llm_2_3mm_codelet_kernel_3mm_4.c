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
for (i = 0; i < ni; i++)
    for (k = 0; k < nk; k++) {
        double r = A[i][k];
        for (j = 0; j < nj; j++)
            E[i][j] += r * B[k][j];
    }
}
