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
extern  double us[65][65][65];
extern  double vs[65][65][65];
extern  double ws[65][65][65];
extern  double qs[65][65][65];
extern  double rho_i[65][65][65];
extern  double square[65][65][65];
extern  double u[65][65][65][5];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern double uijk;
extern double up1;
extern double um1;



void loop(){
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            uijk = us[i][j][k];
            up1 = us[i + 1][j][k];
            um1 = us[i - 1][j][k];

            // Control flow based on spatial location: different updates in lower vs upper half of domain
            if (i < grid_points[0] / 2) {
                rhs[i][j][k][0] += dx1tx1 * (u[i + 1][j][k][0] - 2. * u[i][j][k][0] + u[i - 1][j][k][0]) - tx2 * (u[i + 1][j][k][1] - u[i - 1][j][k][1]);
                rhs[i][j][k][1] += dx2tx1 * (u[i + 1][j][k][1] - 2. * u[i][j][k][1] + u[i - 1][j][k][1]) + xxcon2 * con43 * (up1 - 2. * uijk + um1);
            } else {
                // In upper half, skip convective terms for component 1 and focus on diffusion
                rhs[i][j][k][1] += dx2tx1 * (u[i + 1][j][k][1] - 2. * u[i][j][k][1] + u[i - 1][j][k][1]);
            }

            // All regions compute components 2, 3, and 4, but with conditional scaling
            double scale = (k % 2 == 0) ? 1.0 : 0.5;  // Alternate scaling based on k index

            rhs[i][j][k][2] += scale * (dx3tx1 * (u[i + 1][j][k][2] - 2. * u[i][j][k][2] + u[i - 1][j][k][2]) + xxcon2 * (vs[i + 1][j][k] - 2. * vs[i][j][k] + vs[i - 1][j][k]));
            rhs[i][j][k][3] += scale * (dx4tx1 * (u[i + 1][j][k][3] - 2. * u[i][j][k][3] + u[i - 1][j][k][3]) + xxcon2 * (ws[i + 1][j][k] - 2. * ws[i][j][k] + ws[i - 1][j][k]));

            // Full update for energy equation, unconditionally
            rhs[i][j][k][4] = rhs[i][j][k][4] + dx5tx1 * (u[i + 1][j][k][4] - 2. * u[i][j][k][4] + u[i - 1][j][k][4]) + xxcon3 * (qs[i + 1][j][k] - 2. * qs[i][j][k] + qs[i - 1][j][k]) + xxcon4 * (up1 * up1 - 2. * uijk * uijk + um1 * um1) + xxcon5 * (u[i + 1][j][k][4] * rho_i[i + 1][j][k] - 2. * u[i][j][k][4] * rho_i[i][j][k] + u[i - 1][j][k][4] * rho_i[i - 1][j][k]) - tx2 * ((c1 * u[i + 1][j][k][4] - c2 * square[i + 1][j][k]) * up1 - (c1 * u[i - 1][j][k][4] - c2 * square[i - 1][j][k]) * um1);
        }
    }
}
}
