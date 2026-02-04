#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nk;
extern double B[1100][900];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
for (i = 0; i < nk * nj; i++) {
    int local_i = i / nj;
    int local_j = i % nj;
    B[local_i][local_j] = (double)(local_i * (local_j + 1) % nj) / nj;
}
}
