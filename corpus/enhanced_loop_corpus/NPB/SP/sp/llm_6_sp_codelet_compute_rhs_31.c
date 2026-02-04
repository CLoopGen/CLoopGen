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
    for (i = 3 * 1; i <= grid_points[0] - 3 * 1 - 1; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                double temp = u[m][i - 2][j][k] - 4. * u[m][i - 1][j][k] + 6. * u[m][i][j][k] - 4. * u[m][i + 1][j][k] + u[m][i + 2][j][k];
                rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * temp;
            }
        }
    }
}
}
