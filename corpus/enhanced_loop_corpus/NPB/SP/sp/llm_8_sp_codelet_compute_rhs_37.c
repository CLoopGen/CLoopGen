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
        for (j = 3 * 1; j <= grid_points[1] - 3 * 1 - 1; j += 2) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                double temp1 = u[m][i][j-2][k] - 4.0 * u[m][i][j-1][k];
                double temp2 = 6.0 * u[m][i][j][k] - 4.0 * u[m][i][j+1][k];
                double temp3 = u[m][i][j+2][k];
                rhs[m][i][j][k] -= dssp * (temp1 + temp2 + temp3);
            }
        }
    }
}
}
