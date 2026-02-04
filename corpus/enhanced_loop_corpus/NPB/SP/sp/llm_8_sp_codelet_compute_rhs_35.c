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
        for (k = 2; k <= grid_points[2] - 3; k++) {
            rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (
                6.0 * u[m][i][j][k] 
                - 4.0 * u[m][i][j + 1][k] 
                + 1.0 * u[m][i][j + 2][k]
                - 2.0 * u[m][i][j - 1][k] 
                + 0.5 * u[m][i][j + 3][k]
            );
        }
    }
}
}
