#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nl;
extern double C[900][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nj; i++)
        for (j = 1; j < nl; j++)
            C[i][j] = (C[i][j-1] + (double)((i * (j + 3) + 1) % nl)) / nl;
}
