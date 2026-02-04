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
            tmp1 = 1.0 / u[i][j][k][0];
            tmp2 = tmp1 * tmp1;
            tmp3 = tmp1 * tmp2;

            double u1 = u[i][j][k][1], u2 = u[i][j][k][2], u3 = u[i][j][k][3], u4 = u[i][j][k][4];
            double u1sq = u1 * u1, u2sq = u2 * u2, u3sq = u3 * u3;

            // Reuse common subexpressions to increase arithmetic intensity
            double tmp1_u3 = tmp1 * u3;
            double tmp2_u3 = tmp2 * u3;
            double tmp2_u1 = tmp2 * u1;
            double tmp2_u2 = tmp2 * u2;
            double sum_usq_tmp2 = (u1sq + u2sq + u3sq) * tmp2;
            double sum_usq_3u3sq_tmp2 = (u1sq + u2sq + 3.0 * u3sq) * tmp2;

            // Compute fjac with reduced redundancy
            fjac[i][j][k][0][0] = 0.; fjac[i][j][k][0][1] = 0.; fjac[i][j][k][0][2] = 0.;
            fjac[i][j][k][0][3] = 1.; fjac[i][j][k][0][4] = 0.;

            fjac[i][j][k][1][0] = -u1 * tmp2_u3;
            fjac[i][j][k][1][1] = u3 * tmp1;
            fjac[i][j][k][1][2] = 0.;
            fjac[i][j][k][1][3] = u1 * tmp1;
            fjac[i][j][k][1][4] = 0.;

            fjac[i][j][k][2][0] = -u2 * tmp2_u3;
            fjac[i][j][k][2][1] = 0.;
            fjac[i][j][k][2][2] = u3 * tmp1;
            fjac[i][j][k][2][3] = u2 * tmp1;
            fjac[i][j][k][2][4] = 0.;

            fjac[i][j][k][3][0] = -u3 * tmp2_u3 + 0.5 * c2 * sum_usq_tmp2;
            fjac[i][j][k][3][1] = -c2 * u1 * tmp1;
            fjac[i][j][k][3][2] = -c2 * u2 * tmp1;
            fjac[i][j][k][3][3] = (2.0 - c2) * tmp1_u3;
            fjac[i][j][k][3][4] = c2;

            fjac[i][j][k][4][0] = (c2 * sum_usq_tmp2 - c1 * u4 * tmp1) * tmp1_u3;
            fjac[i][j][k][4][1] = -c2 * tmp2_u1 * u3;
            fjac[i][j][k][4][2] = -c2 * tmp2_u2 * u3;
            fjac[i][j][k][4][3] = c1 * u4 * tmp1 - 0.5 * c2 * sum_usq_3u3sq_tmp2;
            fjac[i][j][k][4][4] = c1 * tmp1_u3;

            // njac computations with factored constants and expressions
            double c3c4_t1 = c3c4 * tmp1;
            double c3c4_t2 = c3c4 * tmp2;
            double dc1 = (c3c4 - c1345);
            double dc3 = (con43 * c3c4 - c1345);

            njac[i][j][k][0][0] = njac[i][j][k][0][1] = njac[i][j][k][0][2] = 
            njac[i][j][k][0][3] = njac[i][j][k][0][4] = 0.;

            njac[i][j][k][1][0] = -c3c4_t2 * u1;
            njac[i][j][k][1][1] = c3c4_t1;
            njac[i][j][k][1][2] = njac[i][j][k][1][3] = njac[i][j][k][1][4] = 0.;

            njac[i][j][k][2][0] = -c3c4_t2 * u2;
            njac[i][j][k][2][1] = 0.;
            njac[i][j][k][2][2] = c3c4_t1;
            njac[i][j][k][2][3] = njac[i][j][k][2][4] = 0.;

            njac[i][j][k][3][0] = -con43 * c3c4_t2 * u3;
            njac[i][j][k][3][1] = njac[i][j][k][3][2] = 0.;
            njac[i][j][k][3][3] = con43 * c3 * c4 * tmp1;
            njac[i][j][k][3][4] = 0.;

            njac[i][j][k][4][0] = -dc1 * tmp3 * u1sq - dc1 * tmp3 * u2sq - dc3 * tmp3 * u3sq - c1345 * tmp2 * u4;
            njac[i][j][k][4][1] = dc1 * tmp2 * u1;
            njac[i][j][k][4][2] = dc1 * tmp2 * u2;
            njac[i][j][k][4][3] = dc3 * tmp2 * u3;
            njac[i][j][k][4][4] = c1345 * tmp1;
        }
    }
}
}
