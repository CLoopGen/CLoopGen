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
        for (j = 2; j <= grid_points[1] - 3; j++) {
            for (k = 2; k <= grid_points[2] - 3; k++) {
                double temp1 = u[m][i-1][j][k] + u[m][i+1][j][k];
                double temp2 = u[m][i][j][k];
                double temp3 = u[m][i+2][j][k];
                rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (-4.0 * temp1 + 6.0 * temp2 - 4.0 * temp3 + temp3);
            }
        }
    }
}
