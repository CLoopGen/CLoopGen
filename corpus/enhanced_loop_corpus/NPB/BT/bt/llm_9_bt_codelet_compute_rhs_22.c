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
for (j = 1; j < grid_points[1] - 1; j += 2) {
    for (k = 1; k < grid_points[2] - 1; k += 2) {
        for (m = 0; m < 5; m++) {
            double temp = u[i - 2][j][k][m] - 4. * u[i - 1][j][k][m] + 5. * u[i][j][k][m];
            rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * temp;
            if (j + 1 < grid_points[1] - 1 && k + 1 < grid_points[2] - 1) {
                rhs[i][j+1][k][m] = rhs[i][j+1][k][m] - dssp * 
                    (u[i - 2][j+1][k][m] - 4. * u[i - 1][j+1][k][m] + 5. * u[i][j+1][k][m]);
                rhs[i][j][k+1][m] = rhs[i][j][k+1][m] - dssp * 
                    (u[i - 2][j][k+1][m] - 4. * u[i - 1][j][k+1][m] + 5. * u[i][j][k+1][m]);
                rhs[i][j+1][k+1][m] = rhs[i][j+1][k+1][m] - dssp * 
                    (u[i - 2][j+1][k+1][m] - 4. * u[i - 1][j+1][k+1][m] + 5. * u[i][j+1][k+1][m]);
            }
        }
    }
}
}
