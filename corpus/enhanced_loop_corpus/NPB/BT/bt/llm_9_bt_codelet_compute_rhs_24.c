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
        double temp_rhs[5];
        double temp_u[5];
        for (m = 0; m < 5; m++) {
            temp_u[m] = u[i][j][k][m];
        }
        for (m = 0; m < 5; m++) {
            temp_rhs[m] = rhs[i][j][k][m] - dssp * (5. * temp_u[m] - 4. * u[i][j + 1][k][m] + u[i][j + 2][k][m]);
        }
        for (m = 0; m < 5; m++) {
            rhs[i][j][k][m] = temp_rhs[m];
        }
    }
}
}
