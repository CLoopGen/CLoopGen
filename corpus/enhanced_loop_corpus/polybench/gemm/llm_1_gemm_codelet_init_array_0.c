#include <stdio.h>

#include <inttypes.h>

extern int ni;
extern int nj;
extern double C[1000][1100];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < ni * nj; i++) {
    int local_i = i / nj;
    int local_j = i % nj;
    C[local_i][local_j] = (double)((local_i * local_j + 1) % ni) / ni;
}
}
