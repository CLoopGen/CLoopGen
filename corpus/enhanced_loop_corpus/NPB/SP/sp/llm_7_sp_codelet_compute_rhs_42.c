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
    double local_dssp = dssp;
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            double stencil = u[m][i][j][k];
            rhs[m][i][j][k] = rhs[m][i][j][k] 
                            - local_dssp * (-4. * u[m][i][j][k - 1] 
                                           + 6. * stencil 
                                           - 4. * u[m][i][j][k + 1] 
                                           + u[m][i][j][k + 2]);
        }
    }
}
}
