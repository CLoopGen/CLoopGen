#include <stdio.h>

extern  int grid_points[3];
extern  double tx2;
extern  double xxcon2;
extern  double xxcon3;
extern  double xxcon4;
extern  double xxcon5;
extern  double dx1tx1;
extern  double dx2tx1;
extern  double dx3tx1;
extern  double dx4tx1;
extern  double dx5tx1;
extern  double c1;
extern  double c2;
extern  double con43;
extern  double u[5][65][65][65];
extern  double us[65][65][65];
extern  double vs[65][65][65];
extern  double ws[65][65][65];
extern  double qs[65][65][65];
extern  double rho_i[65][65][65];
extern  double square[65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern double uijk;
extern double up1;
extern double um1;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            uijk = us[i][j][k];
            up1 = us[i + 1][j][k];
            um1 = us[i - 1][j][k];

            double temp_rhs0 = dx1tx1 * (u[0][i + 1][j][k] - 2. * u[0][i][j][k] + u[0][i - 1][j][k]) 
                             - tx2 * (u[1][i + 1][j][k] - u[1][i - 1][j][k]);
            double temp_rhs1 = dx2tx1 * (u[1][i + 1][j][k] - 2. * u[1][i][j][k] + u[1][i - 1][j][k]) 
                             + xxcon2 * con43 * (up1 - 2. * uijk + um1) 
                             - tx2 * (u[1][i + 1][j][k] * up1 - u[1][i - 1][j][k] * um1 
                             + (u[4][i + 1][j][k] - square[i + 1][j][k] - u[4][i - 1][j][k] + square[i - 1][j][k]) * c2);
            double temp_rhs2 = dx3tx1 * (u[2][i + 1][j][k] - 2. * u[2][i][j][k] + u[2][i - 1][j][k]) 
                             + xxcon2 * (vs[i + 1][j][k] - 2. * vs[i][j][k] + vs[i - 1][j][k]) 
                             - tx2 * (u[2][i + 1][j][k] * up1 - u[2][i - 1][j][k] * um1);
            double temp_rhs3 = dx4tx1 * (u[3][i + 1][j][k] - 2. * u[3][i][j][k] + u[3][i - 1][j][k]) 
                             + xxcon2 * (ws[i + 1][j][k] - 2. * ws[i][j][k] + ws[i - 1][j][k]) 
                             - tx2 * (u[3][i + 1][j][k] * up1 - u[3][i - 1][j][k] * um1);
            double temp_rhs4 = dx5tx1 * (u[4][i + 1][j][k] - 2. * u[4][i][j][k] + u[4][i - 1][j][k]) 
                             + xxcon3 * (qs[i + 1][j][k] - 2. * qs[i][j][k] + qs[i - 1][j][k]) 
                             + xxcon4 * (up1 * up1 - 2. * uijk * uijk + um1 * um1) 
                             + xxcon5 * (u[4][i + 1][j][k] * rho_i[i + 1][j][k] - 2. * u[4][i][j][k] * rho_i[i][j][k] + u[4][i - 1][j][k] * rho_i[i - 1][j][k]) 
                             - tx2 * ((c1 * u[4][i + 1][j][k] - c2 * square[i + 1][j][k]) * up1 
                             - (c1 * u[4][i - 1][j][k] - c2 * square[i - 1][j][k]) * um1);

            rhs[0][i][j][k] += temp_rhs0;
            rhs[1][i][j][k] += temp_rhs1;
            rhs[2][i][j][k] += temp_rhs2;
            rhs[3][i][j][k] += temp_rhs3;
            rhs[4][i][j][k] += temp_rhs4;
        }
    }
}
}
