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
    for (j = 0; j < nj; j++)
        B[j][i] = (double)(i * (j + 2) % nj) / nj;
}
