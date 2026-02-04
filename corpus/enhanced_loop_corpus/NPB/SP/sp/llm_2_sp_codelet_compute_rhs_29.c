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
for (k = 1; k <= grid_points[2] - 2; k++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (m = 0; m < 5; m++) {
            rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (5. * u[m][i][j][k] - 4. * u[m][i + 1][j][k] + u[m][i + 2][j][k]);
        }
    }
}
}
