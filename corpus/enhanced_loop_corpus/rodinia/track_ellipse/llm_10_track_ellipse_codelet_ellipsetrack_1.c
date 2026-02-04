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
for (i = 0; i < Nc * Np; i++) {
    int idx_i = i / Np;
    int idx_j = i % Np;
    xc[idx_i][0] = (idx_j == 0) ? xc0[idx_i] : xc[idx_i][0];
    yc[idx_i][0] = (idx_j == 0) ? yc0[idx_i] : yc[idx_i][0];
    r[idx_i][idx_j][0] = (double)(R + idx_i) * (R + idx_j);
}
}
