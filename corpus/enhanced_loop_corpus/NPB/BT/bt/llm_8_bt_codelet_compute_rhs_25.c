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
for (i = 2; i < grid_points[0] - 2; i++) {
    for (k = 2; k < grid_points[2] - 2; k++) {
        for (m = 0; m < 5; m++) {
            double temp1 = u[i][j-1][k][m] + u[i][j+1][k][m];
            double temp2 = u[i][j][k][m];
            double temp3 = u[i][j+2][k][m];
            rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (-4.0 * temp1 + 6.0 * temp2 + temp3);
        }
    }
}
}
