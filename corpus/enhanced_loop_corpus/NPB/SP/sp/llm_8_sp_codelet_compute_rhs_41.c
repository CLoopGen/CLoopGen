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
    for (i = 2; i <= grid_points[0] - 3; i++) {
        for (j = 2; j <= grid_points[1] - 3; j++) {
            double temp1 = u[m][i][j][k];
            double temp2 = u[m][i][j][k + 1];
            double temp3 = u[m][i][j][k + 2];
            rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (5.0 * temp1 - 4.0 * temp2 + temp3);
            rhs[m][i][j][k] = rhs[m][i][j][k] + dssp * (u[m][i][j][k - 1] - 4.0 * temp1 + 3.0 * temp2);
        }
    }
}
}
