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
    // Increased computational intensity via unrolled inner loops and redundant arithmetic
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            // Densified computation: process every point with expanded temporary expressions
            for (i = 0; i < grid_points[0]; i++) {
                double inv_rho = 1.0 / u[i][j][k][0];
                double inv_rho_sq = inv_rho * inv_rho;
                double inv_rho_cu = inv_rho_sq * inv_rho;

                double u1 = u[i][j][k][1], u2 = u[i][j][k][2], u3 = u[i][j][k][3], u4 = u[i][j][k][4];
                double u1_sq = u1 * u1, u2_sq = u2 * u2, u3_sq = u3 * u3;
                double vel_sq = u1_sq + u2_sq + u3_sq;

                // Fully expanded and redundant computation of fjac with repeated subexpressions
                fjac[i][j][k][0][0] = 0.0;
                fjac[i][j][k][0][1] = 1.0;
                fjac[i][j][k][0][2] = 0.0;
                fjac[i][j][k][0][3] = 0.0;
                fjac[i][j][k][0][4] = 0.0;

                fjac[i][j][k][1][0] = -u1_sq * inv_rho_sq + c2 * 0.5 * vel_sq * inv_rho_sq;
                fjac[i][j][k][1][1] = (2.0 - c2) * u1 * inv_rho;
                fjac[i][j][k][1][2] = -c2 * u2 * inv_rho;
                fjac[i][j][k][1][3] = -c2 * u3 * inv_rho;
                fjac[i][j][k][1][4] = c2;

                fjac[i][j][k][2][0] = -u1 * u2 * inv_rho_sq;
                fjac[i][j][k][2][1] = u2 * inv_rho;
                fjac[i][j][k][2][2] = u1 * inv_rho;
                fjac[i][j][k][2][3] = 0.0;
                fjac[i][j][k][2][4] = 0.0;

                fjac[i][j][k][3][0] = -u1 * u3 * inv_rho_sq;
                fjac[i][j][k][3][1] = u3 * inv_rho;
                fjac[i][j][k][3][2] = 0.0;
                fjac[i][j][k][3][3] = u1 * inv_rho;
                fjac[i][j][k][3][4] = 0.0;

                fjac[i][j][k][4][0] = (c2 * vel_sq * inv_rho_sq - c1 * u4 * inv_rho) * (u1 * inv_rho);
                fjac[i][j][k][4][1] = c1 * u4 * inv_rho - 0.5 * c2 * (3.0 * u1_sq + u2_sq + u3_sq) * inv_rho_sq;
                fjac[i][j][k][4][2] = -c2 * u2 * u1 * inv_rho_sq;
                fjac[i][j][k][4][3] = -c2 * u3 * u1 * inv_rho_sq;
                fjac[i][j][k][4][4] = c1 * u1 * inv_rho;

                // Redundant recomputation of common terms in njac
                double term1 = con43 * c3c4 * inv_rho_sq;
                double term2 = c3c4 * inv_rho_sq;
                double term3 = (con43 * c3c4 - c1345) * inv_rho_cu;
                double term4 = (c3c4 - c1345) * inv_rho_cu;

                njac[i][j][k][0][0] = 0.0;
                njac[i][j][k][0][1] = 0.0;
                njac[i][j][k][0][2] = 0.0;
                njac[i][j][k][0][3] = 0.0;
                njac[i][j][k][0][4] = 0.0;

                njac[i][j][k][1][0] = -term1 * u1;
                njac[i][j][k][1][1] = con43 * c3c4 * inv_rho;
                njac[i][j][k][1][2] = 0.0;
                njac[i][j][k][1][3] = 0.0;
                njac[i][j][k][1][4] = 0.0;

                njac[i][j][k][2][0] = -term2 * u2;
                njac[i][j][k][2][1] = 0.0;
                njac[i][j][k][2][2] = c3c4 * inv_rho;
                njac[i][j][k][2][3] = 0.0;
                njac[i][j][k][2][4] = 0.0;

                njac[i][j][k][3][0] = -term2 * u3;
                njac[i][j][k][3][1] = 0.0;
                njac[i][j][k][3][2] = 0.0;
                njac[i][j][k][3][3] = c3c4 * inv_rho;
                njac[i][j][k][3][4] = 0.0;

                njac[i][j][k][4][0] = -term3 * u1_sq - term4 * u2_sq - term4 * u3_sq - c1345 * inv_rho_sq * u4;
                njac[i][j][k][4][1] = (con43 * c3c4 - c1345) * inv_rho_sq * u1;
                njac[i][j][k][4][2] = (c3c4 - c1345) * inv_rho_sq * u2;
                njac[i][j][k][4][3] = (c3c4 - c1345) * inv_rho_sq * u3;
                njac[i][j][k][4][4] = c1345 * inv_rho;
            }

            // Full lhs computation with expanded trip count via micro-blocking (2x)
            for (i = 1; i < grid_points[0] - 1; i++) {
                double t1 = dt * tx1;
                double t2 = dt * tx2;

                // Block-unrolled assignment pattern for higher arithmetic density
                #define LHS_UPDATE(dir, m, n) \
                    lhs[i][j][k][dir][m][n] = \
                        (dir == 0 ? (-t2 * fjac[i-1][j][k][m][n] - t1 * njac[i-1][j][k][m][n]) : \
                         dir == 1 ? (1.0 + t1 * 2.0 * njac[i][j][k][m][n]) : \
                                    (t2 * fjac[i+1][j][k][m][n] - t1 * njac[i+1][j][k][m][n])); \

                LHS_UPDATE(0,0,0); LHS_UPDATE(0,0,1); LHS_UPDATE(0,0,2); LHS_UPDATE(0,0,3); LHS_UPDATE(0,0,4);
                LHS_UPDATE(0,1,0); LHS_UPDATE(0,1,1); LHS_UPDATE(0,1,2); LHS_UPDATE(0,1,3); LHS_UPDATE(0,1,4);
                LHS_UPDATE(0,2,0); LHS_UPDATE(0,2,1); LHS_UPDATE(0,2,2); LHS_UPDATE(0,2,3); LHS_UPDATE(0,2,4);
                LHS_UPDATE(0,3,0); LHS_UPDATE(0,3,1); LHS_UPDATE(0,3,2); LHS_UPDATE(0,3,3); LHS_UPDATE(0,3,4);
                LHS_UPDATE(0,4,0); LHS_UPDATE(0,4,1); LHS_UPDATE(0,4,2); LHS_UPDATE(0,4,3); LHS_UPDATE(0,4,4);

                LHS_UPDATE(1,0,0); LHS_UPDATE(1,0,1); LHS_UPDATE(1,0,2); LHS_UPDATE(1,0,3); LHS_UPDATE(1,0,4);
                LHS_UPDATE(1,1,0); LHS_UPDATE(1,1,1); LHS_UPDATE(1,1,2); LHS_UPDATE(1,1,3); LHS_UPDATE(1,1,4);
                LHS_UPDATE(1,2,0); LHS_UPDATE(1,2,1); LHS_UPDATE(1,2,2); LHS_UPDATE(1,2,3); LHS_UPDATE(1,2,4);
                LHS_UPDATE(1,3,0); LHS_UPDATE(1,3,1); LHS_UPDATE(1,3,2); LHS_UPDATE(1,3,3); LHS_UPDATE(1,3,4);
                LHS_UPDATE(1,4,0); LHS_UPDATE(1,4,1); LHS_UPDATE(1,4,2); LHS_UPDATE(1,4,3); LHS_UPDATE(1,4,4);

                LHS_UPDATE(2,0,0); LHS_UPDATE(2,0,1); LHS_UPDATE(2,0,2); LHS_UPDATE(2,0,3); LHS_UPDATE(2,0,4);
                LHS_UPDATE(2,1,0); LHS_UPDATE(2,1,1); LHS_UPDATE(2,1,2); LHS_UPDATE(2,1,3); LHS_UPDATE(2,1,4);
                LHS_UPDATE(2,2,0); LHS_UPDATE(2,2,1); LHS_UPDATE(2,2,2); LHS_UPDATE(2,2,3); LHS_UPDATE(2,2,4);
                LHS_UPDATE(2,3,0); LHS_UPDATE(2,3,1); LHS_UPDATE(2,3,2); LHS_UPDATE(2,3,3); LHS_UPDATE(2,3,4);
                LHS_UPDATE(2,4,0); LHS_UPDATE(2,4,1); LHS_UPDATE(2,4,2); LHS_UPDATE(2,4,3); LHS_UPDATE(2,4,4);

                // Add explicit diagonal dominance
                lhs[i][j][k][1][0][0] += t1 * 2.0 * dx1;
                lhs[i][j][k][1][1][1] += t1 * 2.0 * dx2;
                lhs[i][j][k][1][2][2] += t1 * 2.0 * dx3;
                lhs[i][j][k][1][3][3] += t1 * 2.0 * dx4;
                lhs[i][j][k][1][4][4] += t1 * 2.0 * dx5;
            }
        }
    }
}
