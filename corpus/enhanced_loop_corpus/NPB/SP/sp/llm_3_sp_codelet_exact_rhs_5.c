#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[5][65][65][65];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
    int m, i, j, k;
    int stride_i = 1;
    int stride_j = 65;
    int stride_k = 65 * 65;
    int base_offset;
    double *forcing_ptr = &forcing[0][0][0][0];

    for (m = 0; m < 5; m++) {
        base_offset = m * (65 * 65 * 65);
        for (i = 1; i <= grid_points[0] - 2; i++) {
            for (j = 1; j <= grid_points[1] - 2; j++) {
                for (k = 1; k <= grid_points[2] - 2; k++) {
                    int offset = base_offset + i * stride_i + j * stride_j + k * stride_k;
                    forcing_ptr[offset] = -1. * forcing_ptr[offset];
                }
            }
        }
    }
}
