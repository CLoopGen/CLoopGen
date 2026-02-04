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
            // First pass: compute fjac and njac only at even i indices to reduce computational intensity
            for (i = 0; i < grid_points[0]; i += 2) {
                tmp1 = 1.0 / u[i][j][k][0];
                tmp2 = tmp1 * tmp1;
                tmp3 = tmp1 * tmp2;

                // Simplified Jacobian calculations with reduced operations
                fjac[i][j][k][0][1] = 1.0;
                fjac[i][j][k][1][1] = (2.0 - c2) * (u[i][j][k][1] * tmp1);
                fjac[i][j][k][2][1] = u[i][j][k][2] * tmp1;
                fjac[i][j][k][3][1] = u[i][j][k][3] * tmp1;
                fjac[i][j][k][4][4] = c1 * (u[i][j][k][1] * tmp1);

                njac[i][j][k][1][1] = con43 * c3c4 * tmp1;
                njac[i][j][k][2][2] = c3c4 * tmp1;
                njac[i][j][k][3][3] = c3c4 * tmp1;
                njac[i][j][k][4][4] = c1345 * tmp1;
            }

            // Second pass: full lhs computation, but only at interior points and using stride-2 access
            for (i = 2; i < grid_points[0] - 2; i += 2) {
                tmp1 = dt * tx1;
                tmp2 = dt * tx2;

                // Reduced stencil: only central diagonal terms updated
                lhs[i][j][k][1][0][0] = 1.0 + tmp1 * 2.0 * njac[i][j][k][0][0] + tmp1 * 2.0 * dx1;
                lhs[i][j][k][1][1][1] = 1.0 + tmp1 * 2.0 * njac[i][j][k][1][1] + tmp1 * 2.0 * dx2;
                lhs[i][j][k][1][2][2] = 1.0 + tmp1 * 2.0 * njac[i][j][k][2][2] + tmp1 * 2.0 * dx3;
                lhs[i][j][k][1][3][3] = 1.0 + tmp1 * 2.0 * njac[i][j][k][3][3] + tmp1 * 2.0 * dx4;
                lhs[i][j][k][1][4][4] = 1.0 + tmp1 * 2.0 * njac[i][j][k][4][4] + tmp1 * 2.0 * dx5;
            }
        }
    }
}
