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
    for (i = 1; i <= grid_points[0] - 2; i += 2) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            double term = u[m][i][j-2][k] - 4.0 * u[m][i][j-1][k] + 6.0 * u[m][i][j][k] - 4.0 * u[m][i][j+1][k];
            rhs[m][i][j][k] -= dssp * term;
            if (m + 1 < 5) {
                rhs[m+1][i][j][k] -= dssp * (u[m+1][i][j-2][k] - 4.0 * u[m+1][i][j-1][k] + 6.0 * u[m+1][i][j][k] - 4.0 * u[m+1][i][j+1][k]);
            }
        }
    }
}
}
