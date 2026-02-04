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
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (i = 1; i <= grid_points[0] - 2; i++) {
            // Strided access: accessing every second element in the k-dimension indirectly via pointer arithmetic
            double *u_ptr = &u[m][i][j][k-1];
            rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (
                -4. * u_ptr[0]           // u[m][i][j][k-1]
                + 6. * u_ptr[1]          // u[m][i][j][k]
                - 4. * u_ptr[2]          // u[m][i][j][k+1]
                + u_ptr[3]               // u[m][i][j][k+2]
            );
        }
    }
}
}
