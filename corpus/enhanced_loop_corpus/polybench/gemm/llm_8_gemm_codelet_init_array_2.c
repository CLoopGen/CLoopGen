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
    for (j = 0; j < nj; j += 2) {
        double temp1 = (double)(i * (j + 2) % nj) / nj;
        double temp2 = (double)(i * (j + 3) % nj) / nj;
        B[i][j] = temp1;
        if (j + 1 < nj)
            B[i][j + 1] = temp2;
    }
}
