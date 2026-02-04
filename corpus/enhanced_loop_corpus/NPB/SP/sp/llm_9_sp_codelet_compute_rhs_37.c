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
for (m = 0; m < 5; m++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 3 * 1 + 1; j <= grid_points[1] - 3 * 1 - 2; j++) {
            for (k = 2; k <= grid_points[2] - 3; k++) {
                double diff_j_minus_2 = u[m][i][j-2][k];
                double diff_j_minus_1 = u[m][i][j-1][k];
                double diff_j         = u[m][i][j  ][k];
                double diff_j_plus_1  = u[m][i][j+1][k];
                double diff_j_plus_2  = u[m][i][j+2][k];
                double stencil = diff_j_minus_2 
                               - 4.0 * diff_j_minus_1 
                               + 6.0 * diff_j 
                               - 4.0 * diff_j_plus_1 
                               + diff_j_plus_2;
                rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * stencil;
            }
        }
    }
}
}
