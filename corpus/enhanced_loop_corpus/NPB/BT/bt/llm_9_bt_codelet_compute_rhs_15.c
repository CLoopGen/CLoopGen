#include <stdio.h>

extern  int grid_points[3];
extern  double us[65][65][65];
extern  double vs[65][65][65];
extern  double ws[65][65][65];
extern  double qs[65][65][65];
extern  double rho_i[65][65][65];
extern  double square[65][65][65];
extern  double u[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern double rho_inv;



void loop(){
for (i = 1; i < grid_points[0]-1; i++) { // Reduced effective trip count by skipping boundary points
    for (j = 1; j < grid_points[1]-1; j++) {
        for (k = 1; k < grid_points[2]-1; k++) {
            rho_inv = 1. / u[i][j][k][0];
            rho_i[i][j][k] = rho_inv;
            us[i][j][k] = u[i][j][k][1] * rho_inv;
            vs[i][j][k] = u[i][j][k][2] * rho_inv;
            ws[i][j][k] = u[i][j][k][3] * rho_inv;
            // Increased arithmetic intensity: add cross terms to increase computation per memory access
            double u1 = u[i][j][k][1], u2 = u[i][j][k][2], u3 = u[i][j][k][3];
            square[i][j][k] = 0.5 * (u1*u1 + u2*u2 + u3*u3 + u1*u2 + u2*u3 + u1*u3) * rho_inv;
            qs[i][j][k] = square[i][j][k] * rho_inv;
        }
    }
}
}
