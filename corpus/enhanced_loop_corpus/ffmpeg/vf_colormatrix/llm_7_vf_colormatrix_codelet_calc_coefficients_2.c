#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double yuv_coeff_luma[5][3];
extern double yuv_coeff[5][3][3];
extern double bscale;
extern double rscale;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double prev_bscale = 0.5;
double prev_rscale = 0.5;

for (i = 0; i < 5; i++) {
    yuv_coeff[i][0][0] = yuv_coeff_luma[i][0];
    yuv_coeff[i][0][1] = yuv_coeff_luma[i][1];
    yuv_coeff[i][0][2] = yuv_coeff_luma[i][2];

    if (i > 0) {
        bscale = 0.5 / (yuv_coeff[i-1][0][1] - 1.);
        rscale = 0.5 / (yuv_coeff[i-1][0][2] - 1.);
    } else {
        bscale = 0.5 / (yuv_coeff[i][0][1] - 1.);
        rscale = 0.5 / (yuv_coeff[i][0][2] - 1.);
    }

    yuv_coeff[i][1][0] = bscale * yuv_coeff[i][0][0];
    yuv_coeff[i][1][1] = 0.5;
    yuv_coeff[i][1][2] = bscale * yuv_coeff[i][0][2];

    yuv_coeff[i][2][0] = rscale * yuv_coeff[i][0][0];
    yuv_coeff[i][2][1] = rscale * yuv_coeff[i][0][1];
    yuv_coeff[i][2][2] = 0.5;

    prev_bscale = bscale;
    prev_rscale = rscale;
}
}
