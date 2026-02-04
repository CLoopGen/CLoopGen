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
double temp_us, temp_vs, temp_ws, temp_square;
for (i = 0; i < grid_points[0]; i++) {
    for (j = 0; j < grid_points[1]; j++) {
        for (k = 0; k < grid_points[2]; k++) {
            rho_inv = 1. / u[i][j][k][0];
            rho_i[i][j][k] = rho_inv;
            temp_us = u[i][j][k][1] * rho_inv;
            temp_vs = u[i][j][k][2] * rho_inv;
            temp_ws = u[i][j][k][3] * rho_inv;
            us[i][j][k] = temp_us;
            vs[i][j][k] = temp_vs;
            ws[i][j][k] = temp_ws;
            temp_square = 0.5 * (temp_us * u[i][j][k][1] + temp_vs * u[i][j][k][2] + temp_ws * u[i][j][k][3]);
            square[i][j][k] = temp_square;
            qs[i][j][k] = temp_square * rho_inv;
        }
    }
}
}
