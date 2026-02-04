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
for (j = 1; j < grid_points[1] - 1; ++j) {
    for (k = 1; k < grid_points[2] - 1; ++k) {
        for (i = 0; i < grid_points[0]; ++i) {
            tmp1 = 1.0 / u[i][j][k][0];
            tmp2 = tmp1 * tmp1;
            tmp3 = tmp1 * tmp2;

            // Initialize fjac
            for (int m = 0; m < 5; ++m) {
                for (int n = 0; n < 5; ++n) {
                    fjac[i][j][k][m][n] = 0.0;
                    njac[i][j][k][m][n] = 0.0;
                }
            }

            fjac[i][j][k][0][1] = 1.0;
            fjac[i][j][k][1][0] = -(u[i][j][k][1] * u[i][j][k][1]) * tmp2 + c2 * 0.5 * (u[i][j][k][1]*u[i][j][k][1] + u[i][j][k][2]*u[i][j][k][2] + u[i][j][k][3]*u[i][j][k][3]) * tmp2;
            fjac[i][j][k][1][1] = (2.0 - c2) * (u[i][j][k][1] * tmp1);
            fjac[i][j][k][1][2] = -c2 * u[i][j][k][2] * tmp1;
            fjac[i][j][k][1][3] = -c2 * u[i][j][k][3] * tmp1;
            fjac[i][j][k][1][4] = c2;
            fjac[i][j][k][2][0] = -(u[i][j][k][1] * u[i][j][k][2]) * tmp2;
            fjac[i][j][k][2][1] = u[i][j][k][2] * tmp1;
            fjac[i][j][k][2][2] = u[i][j][k][1] * tmp1;
            fjac[i][j][k][3][0] = -(u[i][j][k][1] * u[i][j][k][3]) * tmp2;
            fjac[i][j][k][3][1] = u[i][j][k][3] * tmp1;
            fjac[i][j][k][3][3] = u[i][j][k][1] * tmp1;
            fjac[i][j][k][4][0] = (c2 * (u[i][j][k][1]*u[i][j][k][1] + u[i][j][k][2]*u[i][j][k][2] + u[i][j][k][3]*u[i][j][k][3]) * tmp2 - c1 * u[i][j][k][4] * tmp1) * (u[i][j][k][1] * tmp1);
            fjac[i][j][k][4][1] = c1 * u[i][j][k][4] * tmp1 - 0.5 * c2 * (3.0*u[i][j][k][1]*u[i][j][k][1] + u[i][j][k][2]*u[i][j][k][2] + u[i][j][k][3]*u[i][j][k][3]) * tmp2;
            fjac[i][j][k][4][2] = -c2 * u[i][j][k][2] * u[i][j][k][1] * tmp2;
            fjac[i][j][k][4][3] = -c2 * u[i][j][k][3] * u[i][j][k][1] * tmp2;
            fjac[i][j][k][4][4] = c1 * u[i][j][k][1] * tmp1;

            njac[i][j][k][1][0] = -con43 * c3c4 * tmp2 * u[i][j][k][1];
            njac[i][j][k][1][1] = con43 * c3c4 * tmp1;
            njac[i][j][k][2][0] = -c3c4 * tmp2 * u[i][j][k][2];
            njac[i][j][k][2][2] = c3c4 * tmp1;
            njac[i][j][k][3][0] = -c3c4 * tmp2 * u[i][j][k][3];
            njac[i][j][k][3][3] = c3c4 * tmp1;
            njac[i][j][k][4][0] = -(con43*c3c4 - c1345)*tmp3*(u[i][j][k][1]*u[i][j][k][1]) 
                                - (c3c4 - c1345)*tmp3*(u[i][j][k][2]*u[i][j][k][2]) 
                                - (c3c4 - c1345)*tmp3*(u[i][j][k][3]*u[i][j][k][3]) 
                                - c1345*tmp2*u[i][j][k][4];
            njac[i][j][k][4][1] = (con43*c3c4 - c1345)*tmp2*u[i][j][k][1];
            njac[i][j][k][4][2] = (c3c4 - c1345)*tmp2*u[i][j][k][2];
            njac[i][j][k][4][3] = (c3c4 - c1345)*tmp2*u[i][j][k][3];
            njac[i][j][k][4][4] = c1345 * tmp1;
        }

        for (i = 1; i < grid_points[0] - 1; ++i) {
            double t1 = dt * tx1;
            double t2 = dt * tx2;

            for (int m = 0; m < 3; ++m) {
                for (int n = 0; n < 5; ++n) {
                    for (int p = 0; p < 5; ++p) {
                        double f_val = (m == 0) ? fjac[i-1][j][k][n][p] : (m == 1 ? fjac[i][j][k][n][p] : fjac[i+1][j][k][n][p]);
                        double n_val = (m == 0) ? njac[i-1][j][k][n][p] : (m == 1 ? njac[i][j][k][n][p] : njac[i+1][j][k][n][p]);
                        double dx_val = (n == 0 && p == 0) ? dx1 : (n == 1 && p == 1) ? dx2 : (n == 2 && p == 2) ? dx3 : (n == 3 && p == 3) ? dx4 : (n == 4 && p == 4) ? dx5 : 0.0;

                        if (m == 0) {
                            lhs[i][j][k][m][n][p] = -t2 * f_val - t1 * n_val - (dx_val > 0 ? t1 * dx_val : 0);
                        } else if (m == 1) {
                            lhs[i][j][k][m][n][p] = 1.0 + 2.0 * t1 * n_val + (dx_val > 0 ? 2.0 * t1 * dx_val : 0);
                        } else {
                            lhs[i][j][k][m][n][p] = t2 * f_val - t1 * n_val - (dx_val > 0 ? t1 * dx_val : 0);
                        }
                    }
                }
            }
        }
    }
}
}
