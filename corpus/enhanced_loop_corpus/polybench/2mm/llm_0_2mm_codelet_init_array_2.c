#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nl;
extern double C[900][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i1;
for (i1 = 0; i1 < nj * nl; i1++) {
    i = i1 / nl;
    j = i1 % nl;
    C[i][j] = (double)((i * (j + 3) + 1) % nl) / nl;
}
}
