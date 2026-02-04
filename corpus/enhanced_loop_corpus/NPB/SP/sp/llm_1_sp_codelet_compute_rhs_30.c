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
    for (j = 1; j <= grid_points[1] - 2; j++) {
        rhs[m][i][j][1] = rhs[m][i][j][1] - dssp * (-4. * u[m][i - 1][j][1] + 6. * u[m][i][j][1] - 4. * u[m][i + 1][j][1] + u[m][i + 2][j][1]);
        for (k = 2; k <= grid_points[2] - 2; k++) {
            rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (-4. * u[m][i - 1][j][k] + 6. * u[m][i][j][k] - 4. * u[m][i + 1][j][k] + u[m][i + 2][j][k]);
        }
    }
}
}
