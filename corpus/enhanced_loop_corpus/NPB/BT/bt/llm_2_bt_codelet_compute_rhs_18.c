#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (j = 1; j < grid_points[1] - 1; j++) {
    for (k = 1; k < grid_points[2] - 1; k++) {
        double *rhs_ptr = &rhs[i][j][k][0];
        double *u_ptr = &u[i][j][k][0];
        for (m = 0; m < 5; m++) {
            rhs_ptr[m] = rhs_ptr[m] - dssp * (5. * u_ptr[m] - 4. * u_ptr[m + 65*65*5] + u_ptr[m + 2*65*65*5]);
        }
    }
}
}
