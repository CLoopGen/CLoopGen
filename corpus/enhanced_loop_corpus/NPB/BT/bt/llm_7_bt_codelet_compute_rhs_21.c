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
            for (m = 0; m < 5; m++) {
                double stencil = u[i - 2][j][k][m] - 4.0 * u[i - 1][j][k][m];
                stencil += 6.0 * u[i][j][k][m] - 4.0 * u[i + 1][j][k][m];
                rhs[i][j][k][m] -= dssp * stencil;
            }
        }
    }
}
