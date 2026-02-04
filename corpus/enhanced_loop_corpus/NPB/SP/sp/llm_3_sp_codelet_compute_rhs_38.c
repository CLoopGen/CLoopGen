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
for (k = 1; k <= grid_points[2] - 2; k++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (m = 0; m < 5; m++) {
            double *rhs_ptr = &rhs[m][i][j][k];
            double *u_j2 = &u[m][i][j-2][k];
            double *u_j1 = &u[m][i][j-1][k];
            double *u_j0 = &u[m][i][j][k];
            double *u_jp1 = &u[m][i][j+1][k];
            
            *rhs_ptr = *rhs_ptr - dssp * (
                *u_j2 - 4.0 * *u_j1 + 6.0 * *u_j0 - 4.0 * *u_jp1
            );
        }
    }
}
}
