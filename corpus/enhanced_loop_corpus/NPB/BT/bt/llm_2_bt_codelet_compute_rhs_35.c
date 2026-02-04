#include <stdio.h>

extern  int grid_points[3];
extern  double dt;
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    int j_start = 1;
    int j_end = grid_points[1] - 1;
    int k_stride = 65 * 5;
    int i_stride = 5;
    for (j = j_start; j < j_end; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            for (i = 1; i < grid_points[0] - 1; i++) {
                double *base = &rhs[i][j][k][0];
                base[0] *= dt;
                base[1] *= dt;
                base[2] *= dt;
                base[3] *= dt;
                base[4] *= dt;
            }
        }
    }
}
