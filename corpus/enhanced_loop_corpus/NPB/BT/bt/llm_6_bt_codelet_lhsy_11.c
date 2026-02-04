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
            double u0 = u[i][j][k][0];
            double u1 = u[i][j][k][1];
            double u2 = u[i][j][k][2];
            double u3 = u[i][j][k][3];
            double u4 = u[i][j][k][4];
            tmp1 = 1.0 / u0;
            tmp2 = tmp1 * tmp1;
            tmp3 = tmp1 * tmp2;

            double t1 = u1 * u2 * tmp2;
            double t2 = u2 * tmp1;
            double t3 = u1 * tmp1;
            double t4 = u2 * u2 * tmp2;
            double t5 = u1 * u1 + u3 * u3;
            double t6 = 0.5 * c2 * ((u1 * u1 + u2 * u2 + u3 * u3) * tmp2);
            double t7 = c2 * u1 * tmp1;
            double t8 = (2.0 - c2) * u2 * tmp1;
            double t9 = c2 * u3 * tmp1;

            fjac[i][j][k][0][0] = 0.0;
            fjac[i][j][k][0][1] = 0.0;
            fjac[i][j][k][0][2] = 1.0;
            fjac[i][j][k][0][3] = 0.0;
            fjac[i][j][k][0][4] = 0.0;
            fjac[i][j][k][1][0] = -t1;
            fjac[i][j][k][1][1] = t2;
            fjac[i][j][k][1][2] = t3;
            fjac[i][j][k][1][3] = 0.0;
            fjac[i][j][k][1][4] = 0.0;
            fjac[i][j][k][2][0] = -t4 + t6;
            fjac[i][j][k][2][1] = -t7;
            fjac[i][j][k][2][2] = t8;
            fjac[i][j][k][2][3] = -t9;
            fjac[i][j][k][2][4] = c2;
            fjac[i][j][k][3][0] = -(u2 * u3) * tmp2;
            fjac[i][j][k][3][1] = 0.0;
            fjac[i][j][k][3][2] = u3 * tmp1;
            fjac[i][j][k][3][3] = u2 * tmp1;
            fjac[i][j][k][3][4] = 0.0;
            fjac[i][j][k][4][0] = (c2 * (u1 * u1 + u2 * u2 + u3 * u3) * tmp2 - c1 * u4 * tmp1) * u2 * tmp1;
            fjac[i][j][k][4][1] = -c2 * u1 * u2 * tmp2;
            fjac[i][j][k][4][2] = c1 * u4 * tmp1 - 0.5 * c2 * (u1 * u1 + 3.0 * u2 * u2 + u3 * u3) * tmp2;
            fjac[i][j][k][4][3] = -c2 * u2 * u3 * tmp2;
            fjac[i][j][k][4][4] = c1 * u2 * tmp1;

            double c3c4_tmp1 = c3c4 * tmp1;
            double c3c4_tmp2 = c3c4 * tmp2;
            double con43_c3c4_tmp2 = con43 * c3c4 * tmp2;
            double factor1 = (c3c4 - c1345) * tmp2;
            double factor2 = (con43 * c3c4 - c1345) * tmp2;

            njac[i][j][k][0][0] = 0.0;
            njac[i][j][k][0][1] = 0.0;
            njac[i][j][k][0][2] = 0.0;
            njac[i][j][k][0][3] = 0.0;
            njac[i][j][k][0][4] = 0.0;
            njac[i][j][k][1][0] = -c3c4_tmp2 * u1;
            njac[i][j][k][1][1] = c3c4_tmp1;
            njac[i][j][k][1][2] = 0.0;
            njac[i][j][k][1][3] = 0.0;
            njac[i][j][k][1][4] = 0.0;
            njac[i][j][k][2][0] = -con43_c3c4_tmp2 * u2;
            njac[i][j][k][2][1] = 0.0;
            njac[i][j][k][2][2] = con43 * c3c4 * tmp1;
            njac[i][j][k][2][3] = 0.0;
            njac[i][j][k][2][4] = 0.0;
            njac[i][j][k][3][0] = -c3c4_tmp2 * u3;
            njac[i][j][k][3][1] = 0.0;
            njac[i][j][k][3][2] = 0.0;
            njac[i][j][k][3][3] = c3c4_tmp1;
            njac[i][j][k][3][4] = 0.0;
            njac[i][j][k][4][0] = -(c3c4 - c1345) * tmp3 * (u1 * u1) 
                                - (con43 * c3c4 - c1345) * tmp3 * (u2 * u2) 
                                - (c3c4 - c1345) * tmp3 * (u3 * u3) 
                                - c1345 * tmp2 * u4;
            njac[i][j][k][4][1] = factor1 * u1;
            njac[i][j][k][4][2] = factor2 * u2;
            njac[i][j][k][4][3] = factor1 * u3;
            njac[i][j][k][4][4] = c1345 * tmp1;
        }
    }
}
}
