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
for (i = 1; i < grid_points[0] - 1; i += 2) {
    for (k = 1; k < grid_points[2] - 1; k += 2) {
        for (m = 0; m < 5; m++) {
            rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (
                -4. * u[i][j-1][k][m] + 
                6. * u[i][j][k][m] - 
                4. * u[i][j+1][k][m] + 
                u[i][j+2][k][m]
            );
            if (i + 1 < grid_points[0] - 1) {
                rhs[i+1][j][k][m] = rhs[i+1][j][k][m] - dssp * (
                    -4. * u[i+1][j-1][k][m] + 
                    6. * u[i+1][j][k][m] - 
                    4. * u[i+1][j+1][k][m] + 
                    u[i+1][j+2][k][m]
                );
            }
            if (k + 1 < grid_points[2] - 1) {
                rhs[i][j][k+1][m] = rhs[i][j][k+1][m] - dssp * (
                    -4. * u[i][j-1][k+1][m] + 
                    6. * u[i][j][k+1][m] - 
                    4. * u[i][j+1][k+1][m] + 
                    u[i][j+2][k+1][m]
                );
            }
        }
    }
}
}
