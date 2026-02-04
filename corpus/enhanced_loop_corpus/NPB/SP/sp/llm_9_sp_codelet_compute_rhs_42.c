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
            double term1 = -4. * u[m][i][j][k - 1];
            double term2 = 6. * u[m][i][j][k];
            double term3 = -4. * u[m][i][j][k + 1];
            double term4 = u[m][i][j][k + 2];
            rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (term1 + term2 + term3 + term4);
            if (m + 1 < 5) {
                rhs[m+1][i][j][k] = rhs[m+1][i][j][k] - dssp * (-4. * u[m+1][i][j][k - 1] + 6. * u[m+1][i][j][k] - 4. * u[m+1][i][j][k + 1] + u[m+1][i][j][k + 2]);
            }
        }
    }
}
}
