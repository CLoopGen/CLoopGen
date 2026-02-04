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
    // Variant 2: Memory Access Pattern Modification - Consecutive Access via Pointer Arithmetic
    double (*restrict rhs_ptr)[65][65][5] = rhs;
    double (*restrict u_ptr)[65][65][5] = u;

    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            for (m = 0; m < 5; m++) {
                double temp = dssp * (-4. * u_ptr[i][j][k-1][m] + 6. * u_ptr[i][j][k][m] - 4. * u_ptr[i][j][k+1][m] + u_ptr[i][j][k+2][m]);
                rhs_ptr[i][j][k][m] -= temp;
            }
        }
    }
}
