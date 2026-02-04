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
for (m = 0; m < 5; m += 2) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j += 2) {
            double temp1 = u[m][i][j][k - 2];
            double temp2 = u[m][i][j][k - 1];
            double temp3 = u[m][i][j][k];
            rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (temp1 - 4.0 * temp2 + 5.0 * temp3);
            if (m + 1 < 5) {
                rhs[m+1][i][j][k] = rhs[m+1][i][j][k] - dssp * (u[m+1][i][j][k - 2] - 4.0 * u[m+1][i][j][k - 1] + 5.0 * u[m+1][i][j][k]);
            }
        }
    }
}
}
