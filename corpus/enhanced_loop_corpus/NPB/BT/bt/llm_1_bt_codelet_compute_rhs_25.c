#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (i = 1; i < grid_points[0] - 1; i++) {
    for (m = 0; m < 5; m++) {
        rhs[i][j][1][m] = rhs[i][j][1][m] - dssp * (-4. * u[i][j - 1][1][m] + 6. * u[i][j][1][m] - 4. * u[i][j + 1][1][m] + u[i][j + 2][1][m]);
    }
}
}
