#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nk;
extern double B[1100][900];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nk; i++)
    for (int k = 0; k < nj; k += 2)
        for (j = k; j < k + 2 && j < nj; j++)
            B[i][j] = (double)(i * (j + 1) % nj) / nj;
}
