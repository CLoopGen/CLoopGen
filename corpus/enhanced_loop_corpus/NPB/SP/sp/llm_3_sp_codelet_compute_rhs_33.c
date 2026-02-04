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
for (k = 1; k <= grid_points[2] - 2; k++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (m = 0; m < 5; m++) {
            double *u_m = &u[m][0][0][0];
            double *rhs_m = &rhs[m][0][0][0];
            rhs_m[i*65*65 + j*65 + k] = rhs_m[i*65*65 + j*65 + k] - dssp * (
                u_m[(i-2)*65*65 + j*65 + k] - 
                4. * u_m[(i-1)*65*65 + j*65 + k] + 
                5. * u_m[i*65*65 + j*65 + k]
            );
        }
    }
}
}
