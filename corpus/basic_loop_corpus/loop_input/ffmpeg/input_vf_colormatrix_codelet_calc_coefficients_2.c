#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double yuv_coeff_luma[5][3] = {
    {1.2, 0.8, 1.4},
    {1.1, 0.7, 1.3},
    {1.3, 0.9, 1.5},
    {1.0, 0.6, 1.2},
    {1.4, 1.0, 1.6}
};

double yuv_coeff[5][3][3];

double bscale;
double rscale;
int i;

void init_vars() {
    for (int idx = 0; idx < 5; ++idx) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                yuv_coeff[idx][j][k] = 0.0;
            }
        }
    }
    bscale = 0.0;
    rscale = 0.0;
    i = 0;
}