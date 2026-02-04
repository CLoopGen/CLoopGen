#include <stdio.h>

#include <inttypes.h>

extern int nj;
extern int nk;
extern double B[1000][900];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int ii, jj;
for (i = 0; i < nk; i++) {
    for (j = 0; j < nj; j++) {
        double sum = 0.0;
        for (ii = 0; ii < 3 && (i + ii) < nk; ii++) {
            for (jj = 0; jj < 3 && (j + jj) < nj; jj++) {
                sum += (double)(((i + ii) * ((j + jj) + 1) + 2) % nj) / (5 * nj);
            }
        }
        B[i][j] = sum / 9.0;
    }
}
}
