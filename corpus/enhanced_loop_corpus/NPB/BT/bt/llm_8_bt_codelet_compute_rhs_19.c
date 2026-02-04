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
for (j = 2; j < grid_points[1] - 2; j++) {
    for (k = 2; k < grid_points[2] - 2; k++) {
        for (m = 0; m < 5; m++) {
            rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (
                -5. * u[i - 2][j][k][m] 
                + 16. * u[i - 1][j][k][m] 
                - 30. * u[i][j][k][m] 
                + 16. * u[i + 1][j][k][m] 
                - 5. * u[i + 2][j][k][m]
            );
        }
    }
}
}
