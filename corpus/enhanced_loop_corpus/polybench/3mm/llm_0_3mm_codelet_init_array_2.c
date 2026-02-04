#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nl;
extern int nm;
extern double C[900][1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int k = 0; k < nj * nm; k++) {
    int i = k / nm;
    int j = k % nm;
    C[i][j] = (double)(i * (j + 3) % nl) / (5 * nl);
}
}
