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
    for (j = 0; j < nj; j++) {
        if (!(i % 2)) {
            B[i][j] = (double)(i * (j + 1) % nj) / nj;
        } else {
            B[i][j] = 0.0;
        }
    }
}
