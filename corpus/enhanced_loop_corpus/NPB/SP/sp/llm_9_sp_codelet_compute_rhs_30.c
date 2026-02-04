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
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k += 2) {
                double term1 = -4.0 * u[m][i-1][j][k];
                double term2 =  6.0 * u[m][i][j][k];
                double term3 = -4.0 * u[m][i+1][j][k];
                double term4 =      u[m][i+2][j][k];
                rhs[m][i][j][k] -= dssp * (term1 + term2 + term3 + term4);

                if (m + 1 < 5) {
                    rhs[m+1][i][j][k] -= dssp * (-4.0 * u[m+1][i-1][j][k] + 6.0 * u[m+1][i][j][k] - 4.0 * u[m+1][i+1][j][k] + u[m+1][i+2][j][k]);
                }
            }
        }
    }
}
