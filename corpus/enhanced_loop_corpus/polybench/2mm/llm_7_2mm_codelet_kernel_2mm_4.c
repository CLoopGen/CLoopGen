#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nj;
extern int nk;
extern double alpha;
extern double tmp[800][900];
extern double A[800][1100];
extern double B[1100][900];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < nk; k++)
    for (i = 0; i < ni; i++)
        for (j = 0; j < nj; j++)
            tmp[i][j] += alpha * A[i][k] * B[k][j];
}
