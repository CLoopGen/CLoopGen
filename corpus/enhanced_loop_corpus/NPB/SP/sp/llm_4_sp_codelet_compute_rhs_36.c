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
    for (i = 1; i <= grid_points[0] - 2; i++) {
        if (i % 2 == 0) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (-4. * u[m][i][j - 1][k] + 6. * u[m][i][j][k] - 4. * u[m][i][j + 1][k] + u[m][i][j + 2][k]);
            }
        } else {
            for (k = 1; k <= grid_points[2] - 2; k += 2) {
                rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (-4. * u[m][i][j - 1][k] + 6. * u[m][i][j][k] - 4. * u[m][i][j + 1][k] + u[m][i][j + 2][k]);
            }
        }
    }
}
}
