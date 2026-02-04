#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[5][65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (k = 2; k < grid_points[2] - 2; k++) {
    for (m = 0; m < 5; m++) {
        for (i = 1; i <= grid_points[0] - 2; i++) {
            double *rhs_ptr = &rhs[m][i][1][k];
            double *u_ptr   = &u[m][i][1][k];
            for (j = 1; j <= grid_points[1] - 2; j++) {
                rhs_ptr[j*65] = rhs_ptr[j*65] - dssp * (u_ptr[j*65 - 2] - 4.0 * u_ptr[j*65 - 1] + 5.0 * u_ptr[j*65]);
            }
        }
    }
}
}
