#include <stdio.h>

extern  int grid_points[3];
extern  double c3c4;
extern  double c1345;
extern  double c1;
extern  double c2;
extern  double c3;
extern  double c4;
extern  double con43;
extern  double u[65][65][65][5];
extern  double fjac[65][65][64][5][5];
extern  double njac[65][65][64][5][5];
extern  double tmp1;
extern  double tmp2;
extern  double tmp3;
extern int i;
extern int j;
extern int k;



void loop(){
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            for (k = 0; k < grid_points[2]; k++) {
                double u0 = u[i][j][k][0];
                double u1 = u[i][j][k][1];
                double u2 = u[i][j][k][2];
                double u3 = u[i][j][k][3];
                double u4 = u[i][j][k][4];

                tmp1 = 1.0 / u0;
                tmp2 = tmp1 * tmp1;
                tmp3 = tmp1 * tmp2;

                double u1u3 = u1 * u3;
                double u2u3 = u2 * u3;
                double u3_sq = u3 * u3;
                double u1_sq = u1 * u1;
                double u2_sq = u2 * u2;
                double sum_u_sq = u1_sq + u2_sq + u3_sq;

                // Reuse computed values to reduce redundant memory accesses and arithmetic
                fjac[i][j][k][0][0] = 0.0;
                fjac[i][j][k][0][1] = 0.0;
                fjac[i][j][k][0][2] = 0.0;
                fjac[i][j][k][0][3] = 1.0;
                fjac[i][j][k][0][4] = 0.0;

                fjac[i][j][k][1][0] = -u1u3 * tmp2;
                fjac[i][j][k][1][1] = u3 * tmp1;
                fjac[i][j][k][1][2] = 0.0;
                fjac[i][j][k][1][3] = u1 * tmp1;
                fjac[i][j][k][1][4] = 0.0;

                fjac[i][j][k][2][0] = -u2u3 * tmp2;
                fjac[i][j][k][2][1] = 0.0;
                fjac[i][j][k][2][2] = u3 * tmp1;
                fjac[i][j][k][2][3] = u2 * tmp1;
                fjac[i][j][k][2][4] = 0.0;

                fjac[i][j][k][3][0] = (-u3_sq + 0.5 * c2 * sum_u_sq) * tmp2;
                fjac[i][j][k][3][1] = -c2 * u1 * tmp1;
                fjac[i][j][k][3][2] = -c2 * u2 * tmp1;
                fjac[i][j][k][3][3] = (2.0 - c2) * u3 * tmp1;
                fjac[i][j][k][3][4] = c2;

                double term40 = (c2 * sum_u_sq * tmp2 - c1 * u4 * tmp1) * (u3 * tmp1);
                fjac[i][j][k][4][0] = term40;
                fjac[i][j][k][4][1] = -c2 * u1u3 * tmp2;
                fjac[i][j][k][4][2] = -c2 * u2u3 * tmp2;
                fjac[i][j][k][4][3] = c1 * u4 * tmp1 - 0.5 * c2 * (u1_sq + u2_sq + 3.0 * u3_sq) * tmp2;
                fjac[i][j][k][4][4] = c1 * u3 * tmp1;

                njac[i][j][k][0][0] = 0.0;
                njac[i][j][k][0][1] = 0.0;
                njac[i][j][k][0][2] = 0.0;
                njac[i][j][k][0][3] = 0.0;
                njac[i][j][k][0][4] = 0.0;

                njac[i][j][k][1][0] = -c3c4 * tmp2 * u1;
                njac[i][j][k][1][1] = c3c4 * tmp1;
                njac[i][j][k][1][2] = 0.0;
                njac[i][j][k][1][3] = 0.0;
                njac[i][j][k][1][4] = 0.0;

                njac[i][j][k][2][0] = -c3c4 * tmp2 * u2;
                njac[i][j][k][2][1] = 0.0;
                njac[i][j][k][2][2] = c3c4 * tmp1;
                njac[i][j][k][2][3] = 0.0;
                njac[i][j][k][2][4] = 0.0;

                njac[i][j][k][3][0] = -con43 * c3c4 * tmp2 * u3;
                njac[i][j][k][3][1] = 0.0;
                njac[i][j][k][3][2] = 0.0;
                njac[i][j][k][3][3] = con43 * c3 * c4 * tmp1;
                njac[i][j][k][3][4] = 0.0;

                double coef1 = (c3c4 - c1345);
                double coef2 = (con43 * c3c4 - c1345);
                njac[i][j][k][4][0] = -coef1 * tmp3 * u1_sq - coef1 * tmp3 * u2_sq - coef2 * tmp3 * u3_sq - c1345 * tmp2 * u4;
                njac[i][j][k][4][1] = coef1 * tmp2 * u1;
                njac[i][j][k][4][2] = coef1 * tmp2 * u2;
                njac[i][j][k][4][3] = coef2 * tmp2 * u3;
                njac[i][j][k][4][4] = c1345 * tmp1;
            }
        }
    }
}
