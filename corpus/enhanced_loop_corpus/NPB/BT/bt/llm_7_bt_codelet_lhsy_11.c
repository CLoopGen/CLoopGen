#include <stdio.h>

extern  int grid_points[3];
extern  double c3c4;
extern  double c1345;
extern  double c1;
extern  double c2;
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
    for (j = 0; j < grid_points[1]; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            tmp1 = 1.0 / u[i][j][k][0];
            tmp2 = tmp1 * tmp1;
            tmp3 = tmp1 * tmp2;

            double utmp[5];
            for (int m = 0; m < 5; m++) {
                utmp[m] = u[i][j][k][m];
            }

            double sq1 = utmp[1] * utmp[1];
            double sq2 = utmp[2] * utmp[2];
            double sq3 = utmp[3] * utmp[3];
            double sum_sq = sq1 + sq2 + sq3;
            double sum_sq_3p = sq1 + 3.0 * sq2 + sq3;

            fjac[i][j][k][0][0] = 0.0;
            fjac[i][j][k][0][1] = 0.0;
            fjac[i][j][k][0][2] = 1.0;
            fjac[i][j][k][0][3] = 0.0;
            fjac[i][j][k][0][4] = 0.0;

            fjac[i][j][k][1][0] = -(utmp[1] * utmp[2]) * tmp2;
            fjac[i][j][k][1][1] = utmp[2] * tmp1;
            fjac[i][j][k][1][2] = utmp[1] * tmp1;
            fjac[i][j][k][1][3] = 0.0;
            fjac[i][j][k][1][4] = 0.0;

            fjac[i][j][k][2][0] = -sq2 * tmp2 + 0.5 * c2 * (sum_sq * tmp2);
            fjac[i][j][k][2][1] = -c2 * utmp[1] * tmp1;
            fjac[i][j][k][2][2] = (2.0 - c2) * utmp[2] * tmp1;
            fjac[i][j][k][2][3] = -c2 * utmp[3] * tmp1;
            fjac[i][j][k][2][4] = c2;

            fjac[i][j][k][3][0] = -(utmp[2] * utmp[3]) * tmp2;
            fjac[i][j][k][3][1] = 0.0;
            fjac[i][j][k][3][2] = utmp[3] * tmp1;
            fjac[i][j][k][3][3] = utmp[2] * tmp1;
            fjac[i][j][k][3][4] = 0.0;

            fjac[i][j][k][4][0] = (c2 * sum_sq * tmp2 - c1 * utmp[4] * tmp1) * utmp[2] * tmp1;
            fjac[i][j][k][4][1] = -c2 * utmp[1] * utmp[2] * tmp2;
            fjac[i][j][k][4][2] = c1 * utmp[4] * tmp1 - 0.5 * c2 * sum_sq_3p * tmp2;
            fjac[i][j][k][4][3] = -c2 * utmp[2] * utmp[3] * tmp2;
            fjac[i][j][k][4][4] = c1 * utmp[2] * tmp1;

            double c3c4_t2 = c3c4 * tmp2;
            double con43_c3c4_t2 = con43 * c3c4 * tmp2;
            double diff_term = (c3c4 - c1345);
            double con_diff_term = (con43 * c3c4 - c1345);

            njac[i][j][k][0][0] = 0.0;
            njac[i][j][k][0][1] = 0.0;
            njac[i][j][k][0][2] = 0.0;
            njac[i][j][k][0][3] = 0.0;
            njac[i][j][k][0][4] = 0.0;

            njac[i][j][k][1][0] = -c3c4_t2 * utmp[1];
            njac[i][j][k][1][1] = c3c4 * tmp1;
            njac[i][j][k][1][2] = 0.0;
            njac[i][j][k][1][3] = 0.0;
            njac[i][j][k][1][4] = 0.0;

            njac[i][j][k][2][0] = -con43_c3c4_t2 * utmp[2];
            njac[i][j][k][2][1] = 0.0;
            njac[i][j][k][2][2] = con43 * c3c4 * tmp1;
            njac[i][j][k][2][3] = 0.0;
            njac[i][j][k][2][4] = 0.0;

            njac[i][j][k][3][0] = -c3c4_t2 * utmp[3];
            njac[i][j][k][3][1] = 0.0;
            njac[i][j][k][3][2] = 0.0;
            njac[i][j][k][3][3] = c3c4 * tmp1;
            njac[i][j][k][3][4] = 0.0;

            njac[i][j][k][4][0] = -diff_term * tmp3 * sq1 
                                - con_diff_term * tmp3 * sq2 
                                - diff_term * tmp3 * sq3 
                                - c1345 * tmp2 * utmp[4];
            njac[i][j][k][4][1] = diff_term * tmp2 * utmp[1];
            njac[i][j][k][4][2] = con_diff_term * tmp2 * utmp[2];
            njac[i][j][k][4][3] = diff_term * tmp2 * utmp[3];
            njac[i][j][k][4][4] = c1345 * tmp1;
        }
    }
}
}
