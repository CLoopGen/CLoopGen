#include <stdio.h>

extern  int grid_points[3];
extern  double ty1;
extern  double ty2;
extern  double dy1;
extern  double dy2;
extern  double dy3;
extern  double dy4;
extern  double dy5;
extern  double dt;
extern  double lhs[65][65][65][3][5][5];
extern  double fjac[65][65][64][5][5];
extern  double njac[65][65][64][5][5];
extern  double tmp1;
extern  double tmp2;
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            double t_local = dt * ty1;
            tmp2 = dt * ty2;
            lhs[i][j][k][0][0][0] = -tmp2 * fjac[i][j - 1][k][0][0] - t_local * njac[i][j - 1][k][0][0] - t_local * dy1;
            lhs[i][j][k][0][0][1] = -tmp2 * fjac[i][j - 1][k][0][1] - t_local * njac[i][j - 1][k][0][1];
            lhs[i][j][k][0][0][2] = -tmp2 * fjac[i][j - 1][k][0][2] - t_local * njac[i][j - 1][k][0][2];
            lhs[i][j][k][0][0][3] = -tmp2 * fjac[i][j - 1][k][0][3] - t_local * njac[i][j - 1][k][0][3];
            lhs[i][j][k][0][0][4] = -tmp2 * fjac[i][j - 1][k][0][4] - t_local * njac[i][j - 1][k][0][4];
            lhs[i][j][k][0][1][0] = -tmp2 * fjac[i][j - 1][k][1][0] - t_local * njac[i][j - 1][k][1][0];
            lhs[i][j][k][0][1][1] = -tmp2 * fjac[i][j - 1][k][1][1] - t_local * njac[i][j - 1][k][1][1] - t_local * dy2;
            lhs[i][j][k][0][1][2] = -tmp2 * fjac[i][j - 1][k][1][2] - t_local * njac[i][j - 1][k][1][2];
            lhs[i][j][k][0][1][3] = -tmp2 * fjac[i][j - 1][k][1][3] - t_local * njac[i][j - 1][k][1][3];
            lhs[i][j][k][0][1][4] = -tmp2 * fjac[i][j - 1][k][1][4] - t_local * njac[i][j - 1][k][1][4];
            lhs[i][j][k][0][2][0] = -tmp2 * fjac[i][j - 1][k][2][0] - t_local * njac[i][j - 1][k][2][0];
            lhs[i][j][k][0][2][1] = -tmp2 * fjac[i][j - 1][k][2][1] - t_local * njac[i][j - 1][k][2][1];
            lhs[i][j][k][0][2][2] = -tmp2 * fjac[i][j - 1][k][2][2] - t_local * njac[i][j - 1][k][2][2] - t_local * dy3;
            lhs[i][j][k][0][2][3] = -tmp2 * fjac[i][j - 1][k][2][3] - t_local * njac[i][j - 1][k][2][3];
            lhs[i][j][k][0][2][4] = -tmp2 * fjac[i][j - 1][k][2][4] - t_local * njac[i][j - 1][k][2][4];
            lhs[i][j][k][0][3][0] = -tmp2 * fjac[i][j - 1][k][3][0] - t_local * njac[i][j - 1][k][3][0];
            lhs[i][j][k][0][3][1] = -tmp2 * fjac[i][j - 1][k][3][1] - t_local * njac[i][j - 1][k][3][1];
            lhs[i][j][k][0][3][2] = -tmp2 * fjac[i][j - 1][k][3][2] - t_local * njac[i][j - 1][k][3][2];
            lhs[i][j][k][0][3][3] = -tmp2 * fjac[i][j - 1][k][3][3] - t_local * njac[i][j - 1][k][3][3] - t_local * dy4;
            lhs[i][j][k][0][3][4] = -tmp2 * fjac[i][j - 1][k][3][4] - t_local * njac[i][j - 1][k][3][4];
            lhs[i][j][k][0][4][0] = -tmp2 * fjac[i][j - 1][k][4][0] - t_local * njac[i][j - 1][k][4][0];
            lhs[i][j][k][0][4][1] = -tmp2 * fjac[i][j - 1][k][4][1] - t_local * njac[i][j - 1][k][4][1];
            lhs[i][j][k][0][4][2] = -tmp2 * fjac[i][j - 1][k][4][2] - t_local * njac[i][j - 1][k][4][2];
            lhs[i][j][k][0][4][3] = -tmp2 * fjac[i][j - 1][k][4][3] - t_local * njac[i][j - 1][k][4][3];
            lhs[i][j][k][0][4][4] = -tmp2 * fjac[i][j - 1][k][4][4] - t_local * njac[i][j - 1][k][4][4] - t_local * dy5;

            lhs[i][j][k][1][0][0] = 1. + t_local * 2. * njac[i][j][k][0][0] + t_local * 2. * dy1;
            lhs[i][j][k][1][0][1] = t_local * 2. * njac[i][j][k][0][1];
            lhs[i][j][k][1][0][2] = t_local * 2. * njac[i][j][k][0][2];
            lhs[i][j][k][1][0][3] = t_local * 2. * njac[i][j][k][0][3];
            lhs[i][j][k][1][0][4] = t_local * 2. * njac[i][j][k][0][4];
            lhs[i][j][k][1][1][0] = t_local * 2. * njac[i][j][k][1][0];
            lhs[i][j][k][1][1][1] = 1. + t_local * 2. * njac[i][j][k][1][1] + t_local * 2. * dy2;
            lhs[i][j][k][1][1][2] = t_local * 2. * njac[i][j][k][1][2];
            lhs[i][j][k][1][1][3] = t_local * 2. * njac[i][j][k][1][3];
            lhs[i][j][k][1][1][4] = t_local * 2. * njac[i][j][k][1][4];
            lhs[i][j][k][1][2][0] = t_local * 2. * njac[i][j][k][2][0];
            lhs[i][j][k][1][2][1] = t_local * 2. * njac[i][j][k][2][1];
            lhs[i][j][k][1][2][2] = 1. + t_local * 2. * njac[i][j][k][2][2] + t_local * 2. * dy3;
            lhs[i][j][k][1][2][3] = t_local * 2. * njac[i][j][k][2][3];
            lhs[i][j][k][1][2][4] = t_local * 2. * njac[i][j][k][2][4];
            lhs[i][j][k][1][3][0] = t_local * 2. * njac[i][j][k][3][0];
            lhs[i][j][k][1][3][1] = t_local * 2. * njac[i][j][k][3][1];
            lhs[i][j][k][1][3][2] = t_local * 2. * njac[i][j][k][3][2];
            lhs[i][j][k][1][3][3] = 1. + t_local * 2. * njac[i][j][k][3][3] + t_local * 2. * dy4;
            lhs[i][j][k][1][3][4] = t_local * 2. * njac[i][j][k][3][4];
            lhs[i][j][k][1][4][0] = t_local * 2. * njac[i][j][k][4][0];
            lhs[i][j][k][1][4][1] = t_local * 2. * njac[i][j][k][4][1];
            lhs[i][j][k][1][4][2] = t_local * 2. * njac[i][j][k][4][2];
            lhs[i][j][k][1][4][3] = t_local * 2. * njac[i][j][k][4][3];
            lhs[i][j][k][1][4][4] = 1. + t_local * 2. * njac[i][j][k][4][4] + t_local * 2. * dy5;

            lhs[i][j][k][2][0][0] = tmp2 * fjac[i][j + 1][k][0][0] - t_local * njac[i][j + 1][k][0][0] - t_local * dy1;
            lhs[i][j][k][2][0][1] = tmp2 * fjac[i][j + 1][k][0][1] - t_local * njac[i][j + 1][k][0][1];
            lhs[i][j][k][2][0][2] = tmp2 * fjac[i][j + 1][k][0][2] - t_local * njac[i][j + 1][k][0][2];
            lhs[i][j][k][2][0][3] = tmp2 * fjac[i][j + 1][k][0][3] - t_local * njac[i][j + 1][k][0][3];
            lhs[i][j][k][2][0][4] = tmp2 * fjac[i][j + 1][k][0][4] - t_local * njac[i][j + 1][k][0][4];
            lhs[i][j][k][2][1][0] = tmp2 * fjac[i][j + 1][k][1][0] - t_local * njac[i][j + 1][k][1][0];
            lhs[i][j][k][2][1][1] = tmp2 * fjac[i][j + 1][k][1][1] - t_local * njac[i][j + 1][k][1][1] - t_local * dy2;
            lhs[i][j][k][2][1][2] = tmp2 * fjac[i][j + 1][k][1][2] - t_local * njac[i][j + 1][k][1][2];
            lhs[i][j][k][2][1][3] = tmp2 * fjac[i][j + 1][k][1][3] - t_local * njac[i][j + 1][k][1][3];
            lhs[i][j][k][2][1][4] = tmp2 * fjac[i][j + 1][k][1][4] - t_local * njac[i][j + 1][k][1][4];
            lhs[i][j][k][2][2][0] = tmp2 * fjac[i][j + 1][k][2][0] - t_local * njac[i][j + 1][k][2][0];
            lhs[i][j][k][2][2][1] = tmp2 * fjac[i][j + 1][k][2][1] - t_local * njac[i][j + 1][k][2][1];
            lhs[i][j][k][2][2][2] = tmp2 * fjac[i][j + 1][k][2][2] - t_local * njac[i][j + 1][k][2][2] - t_local * dy3;
            lhs[i][j][k][2][2][3] = tmp2 * fjac[i][j + 1][k][2][3] - t_local * njac[i][j + 1][k][2][3];
            lhs[i][j][k][2][2][4] = tmp2 * fjac[i][j + 1][k][2][4] - t_local * njac[i][j + 1][k][2][4];
            lhs[i][j][k][2][3][0] = tmp2 * fjac[i][j + 1][k][3][0] - t_local * njac[i][j + 1][k][3][0];
            lhs[i][j][k][2][3][1] = tmp2 * fjac[i][j + 1][k][3][1] - t_local * njac[i][j + 1][k][3][1];
            lhs[i][j][k][2][3][2] = tmp2 * fjac[i][j + 1][k][3][2] - t_local * njac[i][j + 1][k][3][2];
            lhs[i][j][k][2][3][3] = tmp2 * fjac[i][j + 1][k][3][3] - t_local * njac[i][j + 1][k][3][3] - t_local * dy4;
            lhs[i][j][k][2][3][4] = tmp2 * fjac[i][j + 1][k][3][4] - t_local * njac[i][j + 1][k][3][4];
            lhs[i][j][k][2][4][0] = tmp2 * fjac[i][j + 1][k][4][0] - t_local * njac[i][j + 1][k][4][0];
            lhs[i][j][k][2][4][1] = tmp2 * fjac[i][j + 1][k][4][1] - t_local * njac[i][j + 1][k][4][1];
            lhs[i][j][k][2][4][2] = tmp2 * fjac[i][j + 1][k][4][2] - t_local * njac[i][j + 1][k][4][2];
            lhs[i][j][k][2][4][3] = tmp2 * fjac[i][j + 1][k][4][3] - t_local * njac[i][j + 1][k][4][3];
            lhs[i][j][k][2][4][4] = tmp2 * fjac[i][j + 1][k][4][4] - t_local * njac[i][j + 1][k][4][4] - t_local * dy5;
        }
    }
}
}
