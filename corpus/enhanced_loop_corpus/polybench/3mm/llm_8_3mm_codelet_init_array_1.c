#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nk;
extern double B[1000][900];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nk; i++)
    for (j = 0; j < nj; j += 2) {
        double temp1 = (double)(i * (j + 1) + 2);
        double temp2 = (double)(i * (j + 2) + 2);
        B[i][j] = (temp1 / (5 * nj));
        if (j + 1 < nj) {
            B[i][j + 1] = (temp2 / (5 * nj));
        }
    }
}
