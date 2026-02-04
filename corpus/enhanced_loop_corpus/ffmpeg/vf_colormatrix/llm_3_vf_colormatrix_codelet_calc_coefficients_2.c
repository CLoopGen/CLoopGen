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
for (i = 4; i >= 0; i--) {
    const int access_idx = i;
    yuv_coeff[access_idx][0][0] = yuv_coeff_luma[access_idx][0];
    yuv_coeff[access_idx][0][1] = yuv_coeff_luma[access_idx][1];
    yuv_coeff[access_idx][0][2] = yuv_coeff_luma[access_idx][2];
    bscale = 0.5 / (yuv_coeff[access_idx][0][1] - 1.);
    rscale = 0.5 / (yuv_coeff[access_idx][0][2] - 1.);
    yuv_coeff[access_idx][1][0] = bscale * yuv_coeff[access_idx][0][0];
    yuv_coeff[access_idx][1][1] = 0.5;
    yuv_coeff[access_idx][1][2] = bscale * yuv_coeff[access_idx][0][2];
    yuv_coeff[access_idx][2][0] = rscale * yuv_coeff[access_idx][0][0];
    yuv_coeff[access_idx][2][1] = rscale * yuv_coeff[access_idx][0][1];
    yuv_coeff[access_idx][2][2] = 0.5;
}
}
