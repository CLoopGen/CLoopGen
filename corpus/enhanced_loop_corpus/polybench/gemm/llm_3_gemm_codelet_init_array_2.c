#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nk;
extern double B[1200][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nk; i++)
    for (int k = 0; k < nj; k += 2)
        if (k < nj) {
            int j1 = k;
            int j2 = k + 1;
            B[i][j1] = (double)(i * (j1 + 2) % nj) / nj;
            if (j2 < nj)
                B[i][j2] = (double)(i * (j2 + 2) % nj) / nj;
        }
}
