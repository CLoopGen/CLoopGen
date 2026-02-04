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
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            for (m = 0; m < 5; m++) {
                if (u[i][j][k][m] > 0.0) {
                    rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (u[i][j][k - 2][m] - 4. * u[i][j][k - 1][m] + 6. * u[i][j][k][m] - 4. * u[i][j][k + 1][m]);
                }
            }
        }
    }
}
