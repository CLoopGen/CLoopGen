#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *xc0;
extern double *yc0;
extern int Nc;
extern int R;
extern int Np;
extern int i;
extern int j;
extern double **xc;
extern double **yc;
extern double ***r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 1: Strided memory access pattern on r using step size of 2, unrolled by 2
for (i = 0; i < Nc; i++) {
    xc[i][0] = xc0[i];
    yc[i][0] = yc0[i];
    for (j = 0; j < Np; j += 2) {
        if (j + 1 < Np) {
            r[i][j][0] = (double)R;
            r[i][j+1][0] = (double)R;
        } else {
            r[i][j][0] = (double)R;
        }
    }
}
}
