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
    for (i = 0; i < Nc; i++) {
        double temp_x = xc0[i];
        double temp_y = yc0[i];
        for (j = 0; j < Np; j++) {
            r[i][j][0] = (double)R;
        }
        xc[i][0] = temp_x;
        yc[i][0] = temp_y;
    }
}
