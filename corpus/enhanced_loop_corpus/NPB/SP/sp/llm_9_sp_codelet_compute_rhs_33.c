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
    for (j = 1; j <= grid_points[1] - 2; j += 2) {
        for (k = 1; k <= grid_points[2] - 2; k += 2) {
            double term = u[m][i - 2][j][k] - 4.0 * u[m][i - 1][j][k] + 5.0 * u[m][i][j][k];
            rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * term;
            if (j + 1 <= grid_points[1] - 2) {
                rhs[m][i][j+1][k] = rhs[m][i][j+1][k] - dssp * 
                    (u[m][i - 2][j+1][k] - 4.0 * u[m][i - 1][j+1][k] + 5.0 * u[m][i][j+1][k]);
            }
            if (k + 1 <= grid_points[2] - 2) {
                rhs[m][i][j][k+1] = rhs[m][i][j][k+1] - dssp * 
                    (u[m][i - 2][j][k+1] - 4.0 * u[m][i - 1][j][k+1] + 5.0 * u[m][i][j][k+1]);
            }
        }
    }
}
}
