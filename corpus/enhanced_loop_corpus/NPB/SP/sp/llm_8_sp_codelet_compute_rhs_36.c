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
            for (k = 2; k <= grid_points[2] - 3; k++) {
                double temp1 = u[m][i][j-2][k];
                double temp2 = u[m][i][j-1][k];
                double temp3 = u[m][i][j][k];
                double temp4 = u[m][i][j+1][k];
                double temp5 = u[m][i][j+2][k];
                rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (
                    temp1 - 4. * temp2 + 6. * temp3 - 4. * temp4 + temp5
                );
            }
        }
    }
}
}
