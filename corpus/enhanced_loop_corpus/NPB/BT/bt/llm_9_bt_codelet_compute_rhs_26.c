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
    for (j = 4; j < grid_points[1] - 4; j += 2) {
        for (k = 1; k < grid_points[2] - 1; k += 2) {
            for (m = 0; m < 5; m++) {
                double term1 = u[i][j-2][k][m] - 4. * u[i][j-1][k][m];
                double term2 = 6. * u[i][j][k][m] - 4. * u[i][j+1][k][m];
                double term3 = u[i][j+2][k][m];
                rhs[i][j][k][m] = rhs[i][j][k][m] - dssp * (term1 + term2 + term3);
                
                // Additional computational work to increase arithmetic intensity
                rhs[i][j][k][m] *= 1.001;
                rhs[i][j][k][m] += 1e-8 * u[i][j][k][m];
            }
        }
    }
}
}
