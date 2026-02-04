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
    double factor = dssp * 1.0;
    for (i = 1; i <= grid_points[0] - 2; i++) {
        double u_val_center = u[m][i][j][1]; 
        for (k = 1; k <= grid_points[2] - 2; k++) {
            double left_term = (k == 1) ? u[m][i][j - 1][k] : rhs[m][i][j][k-1];
            rhs[m][i][j][k] = rhs[m][i][j][k] - factor * (-4. * left_term + 6. * u[m][i][j][k] - 4. * u[m][i][j + 1][k] + u[m][i][j + 2][k]);
        }
    }
}
}
