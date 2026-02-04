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
    k = 1;
    if (k < grid_points[2] - 1) {
        do {
            for (m = 0; m < 5; m++) {
                rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (5. * u[i][j][k][m] - 4. * u[i][j + 1][k][m] + u[i][j + 2][k][m]);
            }
            k++;
        } while (k < grid_points[2] - 1);
    }
}
}
