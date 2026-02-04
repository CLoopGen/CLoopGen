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
for (i = 0; i < 5; i++) {
    yuv_coeff[i][0][0] = yuv_coeff_luma[i][0];
    yuv_coeff[i][0][1] = yuv_coeff_luma[i][1];
    yuv_coeff[i][0][2] = yuv_coeff_luma[i][2];
    bscale = 0.5 / (yuv_coeff[i][0][1] - 1.0);
    rscale = 0.5 / (yuv_coeff[i][0][2] - 1.0);
    double temp_b0 = bscale * yuv_coeff[i][0][0];
    double temp_b2 = bscale * yuv_coeff[i][0][2];
    double temp_r0 = rscale * yuv_coeff[i][0][0];
    double temp_r1 = rscale * yuv_coeff[i][0][1];
    yuv_coeff[i][1][0] = temp_b0;
    yuv_coeff[i][1][1] = 0.5;
    yuv_coeff[i][1][2] = temp_b2;
    yuv_coeff[i][2][0] = temp_r0;
    yuv_coeff[i][2][1] = temp_r1;
    yuv_coeff[i][2][2] = 0.5;
}
}
