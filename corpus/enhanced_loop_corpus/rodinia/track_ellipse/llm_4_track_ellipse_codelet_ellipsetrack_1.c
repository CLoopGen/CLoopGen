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
// Variant 2: Consecutive memory layout simulation via pointer arithmetic and local blocking
double *xc_ptr = xc0;
double *yc_ptr = yc0;
for (i = 0; i < Nc; i++) {
    xc[i][0] = *xc_ptr++;
    yc[i][0] = *yc_ptr++;
    double ***r_ptr = &r[i];
    for (j = 0; j < Np; j++) {
        (*r_ptr)[j][0] = (double)R;
    }
}
}
