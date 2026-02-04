#include <stdio.h>

extern  int grid_points[3];
extern  double tx1;
extern  double tx2;
extern  double dx1;
extern  double dx2;
extern  double dx3;
extern  double dx4;
extern  double dx5;
extern  double dt;
extern  double c3c4;
extern  double c1345;
extern  double c1;
extern  double c2;
extern  double con43;
extern  double u[65][65][65][5];
extern  double lhs[65][65][65][3][5][5];
extern  double fjac[65][65][64][5][5];
extern  double njac[65][65][64][5][5];
extern  double tmp1;
extern  double tmp2;
extern  double tmp3;
extern int i;
extern int j;
extern int k;



void loop(){
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            // Combined loop with early termination condition
            for (i = 0; i < grid_points[0]; i++) {
                tmp1 = 1. / u[i][j][k][0];
                tmp2 = tmp1 * tmp1;
                tmp3 = tmp1 * tmp2;

                // Skip computation if density is too low
                if (u[i][j][k][0] < 1e-6) continue;

                fjac[i][j][k][0][0] = 0.;
                fjac[i][j][k][0][1] = 1.;
                fjac[i][j][k][0][2] = 0.;
                fjac[i][j][k][0][3] = 0.;
                fjac[i][j][k][0][4] = 0.;

                double usq = u[i][j][k][1] * u[i][j][k][1] + u[i][j][k][2] * u[i][j][k][2] + u[i][j][k][3] * u[i][j][k][3];

                fjac[i][j][k][1][0] = -u[i][j][k][1] * u[i][j][k][1] * tmp2 + c2 * 0.5 * usq * tmp2;
                fjac[i][j][k][1][1] = (2. - c2) * (u[i][j][k][1] * tmp1);
                fjac[i][j][k][1][2] = -c2 * (u[i][j][k][2] * tmp1);
                fjac[i][j][k][1][3] = -c2 * (u[i][j][k][3] * tmp1);
                fjac[i][j][k][1][4] = c2;

                fjac[i][j][k][2][0] = -(u[i][j][k][1] * u[i][j][k][2]) * tmp2;
                fjac[i][j][k][2][1] = u[i][j][k][2] * tmp1;
                fjac[i][j][k][2][2] = u[i][j][k][1] * tmp1;
                fjac[i][j][k][2][3] = 0.;
                fjac[i][j][k][2][4] = 0.;

                fjac[i][j][k][3][0] = -(u[i][j][k][1] * u[i][j][k][3]) * tmp2;
                fjac[i][j][k][3][1] = u[i][j][k][3] * tmp1;
                fjac[i][j][k][3][2] = 0.;
                fjac[i][j][k][3][3] = u[i][j][k][1] * tmp1;
                fjac[i][j][k][3][4] = 0.;

                fjac[i][j][k][4][0] = (c2 * usq * tmp2 - c1 * u[i][j][k][4] * tmp1) * (u[i][j][k][1] * tmp1);
                fjac[i][j][k][4][1] = c1 * u[i][j][k][4] * tmp1 - 0.5 * c2 * (3. * u[i][j][k][1] * u[i][j][k][1] + u[i][j][k][2] * u[i][j][k][2] + u[i][j][k][3] * u[i][j][k][3]) * tmp2;
                fjac[i][j][k][4][2] = -c2 * (u[i][j][k][2] * u[i][j][k][1]) * tmp2;
                fjac[i][j][k][4][3] = -c2 * (u[i][j][k][3] * u[i][j][k][1]) * tmp2;
                fjac[i][j][k][4][4] = c1 * (u[i][j][k][1] * tmp1);

                njac[i][j][k][0][0] = 0.;
                njac[i][j][k][0][1] = 0.;
                njac[i][j][k][0][2] = 0.;
                njac[i][j][k][0][3] = 0.;
                njac[i][j][k][0][4] = 0.;

                njac[i][j][k][1][0] = -con43 * c3c4 * tmp2 * u[i][j][k][1];
                njac[i][j][k][1][1] = con43 * c3c4 * tmp1;
                njac[i][j][k][1][2] = 0.;
                njac[i][j][k][1][3] = 0.;
                njac[i][j][k][1][4] = 0.;

                njac[i][j][k][2][0] = -c3c4 * tmp2 * u[i][j][k][2];
                njac[i][j][k][2][1] = 0.;
                njac[i][j][k][2][2] = c3c4 * tmp1;
                njac[i][j][k][2][3] = 0.;
                njac[i][j][k][2][4] = 0.;

                njac[i][j][k][3][0] = -c3c4 * tmp2 * u[i][j][k][3];
                njac[i][j][k][3][1] = 0.;
                njac[i][j][k][3][2] = 0.;
                njac[i][j][k][3][3] = c3c4 * tmp1;
                njac[i][j][k][3][4] = 0.;

                double diff_term1 = (con43 * c3c4 - c1345);
                double diff_term2 = (c3c4 - c1345);

                njac[i][j][k][4][0] = -diff_term1 * tmp3 * (u[i][j][k][1] * u[i][j][k][1])
                                    - diff_term2 * tmp3 * (u[i][j][k][2] * u[i][j][k][2])
                                    - diff_term2 * tmp3 * (u[i][j][k][3] * u[i][j][k][3])
                                    - c1345 * tmp2 * u[i][j][k][4];
                njac[i][j][k][4][1] = diff_term1 * tmp2 * u[i][j][k][1];
                njac[i][j][k][4][2] = diff_term2 * tmp2 * u[i][j][k][2];
                njac[i][j][k][4][3] = diff_term2 * tmp2 * u[i][j][k][3];
                njac[i][j][k][4][4] = c1345 * tmp1;
            }

            // Reuse same loop structure but only update LHS for central band
            int start_i = (grid_points[0] > 5) ? 2 : 1;
            int end_i = (grid_points[0] > 5) ? grid_points[0] - 2 : grid_points[0] - 1;

            for (i = start_i; i < end_i; i++) {
                // Skip boundary-adjacent elements in small grids
                if (grid_points[0] <= 5 && (i == 1 || i == grid_points[0] - 2)) continue;

                tmp1 = dt * tx1;
                tmp2 = dt * tx2;

                lhs[i][j][k][0][0][0] = -tmp2 * fjac[i - 1][j][k][0][0] - tmp1 * njac[i - 1][j][k][0][0] - tmp1 * dx1;
                lhs[i][j][k][0][0][1] = -tmp2 * fjac[i - 1][j][k][0][1] - tmp1 * njac[i - 1][j][k][0][1];
                lhs[i][j][k][0][0][2] = -tmp2 * fjac[i - 1][j][k][0][2] - tmp1 * njac[i - 1][j][k][0][2];
                lhs[i][j][k][0][0][3] = -tmp2 * fjac[i - 1][j][k][0][3] - tmp1 * njac[i - 1][j][k][0][3];
                lhs[i][j][k][0][0][4] = -tmp2 * fjac[i - 1][j][k][0][4] - tmp1 * njac[i - 1][j][k][0][4];

                lhs[i][j][k][0][1][0] = -tmp2 * fjac[i - 1][j][k][1][0] - tmp1 * njac[i - 1][j][k][1][0];
                lhs[i][j][k][0][1][1] = -tmp2 * fjac[i - 1][j][k][1][1] - tmp1 * njac[i - 1][j][k][1][1] - tmp1 * dx2;
                lhs[i][j][k][0][1][2] = -tmp2 * fjac[i - 1][j][k][1][2] - tmp1 * njac[i - 1][j][k][1][2];
                lhs[i][j][k][0][1][3] = -tmp2 * fjac[i - 1][j][k][1][3] - tmp1 * njac[i - 1][j][k][1][3];
                lhs[i][j][k][0][1][4] = -tmp2 * fjac[i - 1][j][k][1][4] - tmp1 * njac[i - 1][j][k][1][4];

                lhs[i][j][k][0][2][0] = -tmp2 * fjac[i - 1][j][k][2][0] - tmp1 * njac[i - 1][j][k][2][0];
                lhs[i][j][k][0][2][1] = -tmp2 * fjac[i - 1][j][k][2][1] - tmp1 * njac[i - 1][j][k][2][1];
                lhs[i][j][k][0][2][2] = -tmp2 * fjac[i - 1][j][k][2][2] - tmp1 * njac[i - 1][j][k][2][2] - tmp1 * dx3;
                lhs[i][j][k][0][2][3] = -tmp2 * fjac[i - 1][j][k][2][3] - tmp1 * njac[i - 1][j][k][2][3];
                lhs[i][j][k][0][2][4] = -tmp2 * fjac[i - 1][j][k][2][4] - tmp1 * njac[i - 1][j][k][2][4];

                lhs[i][j][k][0][3][0] = -tmp2 * fjac[i - 1][j][k][3][0] - tmp1 * njac[i - 1][j][k][3][0];
                lhs[i][j][k][0][3][1] = -tmp2 * fjac[i - 1][j][k][3][1] - tmp1 * njac[i - 1][j][k][3][1];
                lhs[i][j][k][0][3][2] = -tmp2 * fjac[i - 1][j][k][3][2] - tmp1 * njac[i - 1][j][k][3][2];
                lhs[i][j][k][0][3][3] = -tmp2 * fjac[i - 1][j][k][3][3] - tmp1 * njac[i - 1][j][k][3][3] - tmp1 * dx4;
                lhs[i][j][k][0][3][4] = -tmp2 * fjac[i - 1][j][k][3][4] - tmp1 * njac[i - 1][j][k][3][4];

                lhs[i][j][k][0][4][0] = -tmp2 * fjac[i - 1][j][k][4][0] - tmp1 * njac[i - 1][j][k][4][0];
                lhs[i][j][k][0][4][1] = -tmp2 * fjac[i - 1][j][k][4][1] - tmp1 * njac[i - 1][j][k][4][1];
                lhs[i][j][k][0][4][2] = -tmp2 * fjac[i - 1][j][k][4][2] - tmp1 * njac[i - 1][j][k][4][2];
                lhs[i][j][k][0][4][3] = -tmp2 * fjac[i - 1][j][k][4][3] - tmp1 * njac[i - 1][j][k][4][3];
                lhs[i][j][k][0][4][4] = -tmp2 * fjac[i - 1][j][k][4][4] - tmp1 * njac[i - 1][j][k][4][4] - tmp1 * dx5;

                lhs[i][j][k][1][0][0] = 1. + tmp1 * 2. * njac[i][j][k][0][0] + tmp1 * 2. * dx1;
                lhs[i][j][k][1][0][1] = tmp1 * 2. * njac[i][j][k][0][1];
                lhs[i][j][k][1][0][2] = tmp1 * 2. * njac[i][j][k][0][2];
                lhs[i][j][k][1][0][3] = tmp1 * 2. * njac[i][j][k][0][3];
                lhs[i][j][k][1][0][4] = tmp1 * 2. * njac[i][j][k][0][4];

                lhs[i][j][k][1][1][0] = tmp1 * 2. * njac[i][j][k][1][0];
                lhs[i][j][k][1][1][1] = 1. + tmp1 * 2. * njac[i][j][k][1][1] + tmp1 * 2. * dx2;
                lhs[i][j][k][1][1][2] = tmp1 * 2. * njac[i][j][k][1][2];
                lhs[i][j][k][1][1][3] = tmp1 * 2. * njac[i][j][k][1][3];
                lhs[i][j][k][1][1][4] = tmp1 * 2. * njac[i][j][k][1][4];

                lhs[i][j][k][1][2][0] = tmp1 * 2. * njac[i][j][k][2][0];
                lhs[i][j][k][1][2][1] = tmp1 * 2. * njac[i][j][k][2][1];
                lhs[i][j][k][1][2][2] = 1. + tmp1 * 2. * njac[i][j][k][2][2] + tmp1 * 2. * dx3;
                lhs[i][j][k][1][2][3] = tmp1 * 2. * njac[i][j][k][2][3];
                lhs[i][j][k][1][2][4] = tmp1 * 2. * njac[i][j][k][2][4];

                lhs[i][j][k][1][3][0] = tmp1 * 2. * njac[i][j][k][3][0];
                lhs[i][j][k][1][3][1] = tmp1 * 2. * njac[i][j][k][3][1];
                lhs[i][j][k][1][3][2] = tmp1 * 2. * njac[i][j][k][3][2];
                lhs[i][j][k][1][3][3] = 1. + tmp1 * 2. * njac[i][j][k][3][3] + tmp1 * 2. * dx4;
                lhs[i][j][k][1][3][4] = tmp1 * 2. * njac[i][j][k][3][4];

                lhs[i][j][k][1][4][0] = tmp1 * 2. * njac[i][j][k][4][0];
                lhs[i][j][k][1][4][1] = tmp1 * 2. * njac[i][j][k][4][1];
                lhs[i][j][k][1][4][2] = tmp1 * 2. * njac[i][j][k][4][2];
                lhs[i][j][k][1][4][3] = tmp1 * 2. * njac[i][j][k][4][3];
                lhs[i][j][k][1][4][4] = 1. + tmp1 * 2. * njac[i][j][k][4][4] + tmp1 * 2. * dx5;

                lhs[i][j][k][2][0][0] = tmp2 * fjac[i + 1][j][k][0][0] - tmp1 * njac[i + 1][j][k][0][0] - tmp1 * dx1;
                lhs[i][j][k][2][0][1] = tmp2 * fjac[i + 1][j][k][0][1] - tmp1 * njac[i + 1][j][k][0][1];
                lhs[i][j][k][2][0][2] = tmp2 * fjac[i + 1][j][k][0][2] - tmp1 * njac[i + 1][j][k][0][2];
                lhs[i][j][k][2][0][3] = tmp2 * fjac[i + 1][j][k][0][3] - tmp1 * njac[i + 1][j][k][0][3];
                lhs[i][j][k][2][0][4] = tmp2 * fjac[i + 1][j][k][0][4] - tmp1 * njac[i + 1][j][k][0][4];

                lhs[i][j][k][2][1][0] = tmp2 * fjac[i + 1][j][k][1][0] - tmp1 * njac[i + 1][j][k][1][0];
                lhs[i][j][k][2][1][1] = tmp2 * fjac[i + 1][j][k][1][1] - tmp1 * njac[i + 1][j][k][1][1] - tmp1 * dx2;
                lhs[i][j][k][2][1][2] = tmp2 * fjac[i + 1][j][k][1][2] - tmp1 * njac[i + 1][j][k][1][2];
                lhs[i][j][k][2][1][3] = tmp2 * fjac[i + 1][j][k][1][3] - tmp1 * njac[i + 1][j][k][1][3];
                lhs[i][j][k][2][1][4] = tmp2 * fjac[i + 1][j][k][1][4] - tmp1 * njac[i + 1][j][k][1][4];

                lhs[i][j][k][2][2][0] = tmp2 * fjac[i + 1][j][k][2][0] - tmp1 * njac[i + 1][j][k][2][0];
                lhs[i][j][k][2][2][1] = tmp2 * fjac[i + 1][j][k][2][1] - tmp1 * njac[i + 1][j][k][2][1];
                lhs[i][j][k][2][2][2] = tmp2 * fjac[i + 1][j][k][2][2] - tmp1 * njac[i + 1][j][k][2][2] - tmp1 * dx3;
                lhs[i][j][k][2][2][3] = tmp2 * fjac[i + 1][j][k][2][3] - tmp1 * njac[i + 1][j][k][2][3];
                lhs[i][j][k][2][2][4] = tmp2 * fjac[i + 1][j][k][2][4] - tmp1 * njac[i + 1][j][k][2][4];

                lhs[i][j][k][2][3][0] = tmp2 * fjac[i + 1][j][k][3][0] - tmp1 * njac[i + 1][j][k][3][0];
                lhs[i][j][k][2][3][1] = tmp2 * fjac[i + 1][j][k][3][1] - tmp1 * njac[i + 1][j][k][3][1];
                lhs[i][j][k][2][3][2] = tmp2 * fjac[i + 1][j][k][3][2] - tmp1 * njac[i + 1][j][k][3][2];
                lhs[i][j][k][2][3][3] = tmp2 * fjac[i + 1][j][k][3][3] - tmp1 * njac[i + 1][j][k][3][3] - tmp1 * dx4;
                lhs[i][j][k][2][3][4] = tmp2 * fjac[i + 1][j][k][3][4] - tmp1 * njac[i + 1][j][k][3][4];

                lhs[i][j][k][2][4][0] = tmp2 * fjac[i + 1][j][k][4][0] - tmp1 * njac[i + 1][j][k][4][0];
                lhs[i][j][k][2][4][1] = tmp2 * fjac[i + 1][j][k][4][1] - tmp1 * njac[i + 1][j][k][4][1];
                lhs[i][j][k][2][4][2] = tmp2 * fjac[i + 1][j][k][4][2] - tmp1 * njac[i + 1][j][k][4][2];
                lhs[i][j][k][2][4][3] = tmp2 * fjac[i + 1][j][k][4][3] - tmp1 * njac[i + 1][j][k][4][3];
                lhs[i][j][k][2][4][4] = tmp2 * fjac[i + 1][j][k][4][4] - tmp1 * njac[i + 1][j][k][4][4] - tmp1 * dx5;
            }
        }
    }
}
