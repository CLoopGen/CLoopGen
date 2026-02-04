#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nk;
extern double B[1100][900];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j, k;
for (i = 0; i < nk; i++)
    for (j = 0; j < nj; j++)
        for (k = 0; k < 1; k++)
            B[i][j] = (double)(i * (j + 1) % nj) / nj;
}
