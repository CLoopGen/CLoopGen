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
        for (j = 2; j <= grid_points[1] - 3; j++) {
            rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (
                u[m][i][j][k - 2] - 4.0 * u[m][i][j][k - 1] + 6.0 * u[m][i][j][k] 
                - 4.0 * u[m][i][j][k + 1] + u[m][i][j][k + 2]
            );
        }
    }
}
}
