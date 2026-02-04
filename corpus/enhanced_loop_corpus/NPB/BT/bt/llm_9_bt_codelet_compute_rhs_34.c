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
for (i = 1; i < grid_points[0] - 1; i += 2) {
    for (j = 1; j < grid_points[1] - 1; j += 2) {
        for (m = 0; m < 5; m += 2) {
            double term = u[i][j][k-2][m] + u[i][j][k-1][m];
            rhs[i][j][k][m] -= dssp * (5.0 * u[i][j][k][m] - 3.0 * term);
            if (m + 1 < 5) {
                rhs[i][j][k][m+1] -= dssp * (u[i][j][k-2][m+1] - 4.0 * u[i][j][k-1][m+1] + 5.0 * u[i][j][k][m+1]);
            }
        }
    }
}
}
