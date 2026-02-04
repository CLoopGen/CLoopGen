#include <stdio.h>

extern  int grid_points[3];
extern  double tz1;
extern  double tz2;
extern  double dz1;
extern  double dz2;
extern  double dz3;
extern  double dz4;
extern  double dz5;
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
    int i, j, k;
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
#pragma unroll
            for (k = 1; k < grid_points[2] - 1; k += 2) {
                if (k + 1 >= grid_points[2] - 1) break;

                tmp1 = dt * tz1;
                tmp2 = dt * tz2;

                // First k index update
                int k1 = k;
                lhs[i][j][k1][0][0][0] = -tmp2 * fjac[i][j][k1 - 1][0][0] - tmp1 * njac[i][j][k1 - 1][0][0] - tmp1 * dz1;
                lhs[i][j][k1][0][0][1] = -tmp2 * fjac[i][j][k1 - 1][0][1] - tmp1 * njac[i][j][k1 - 1][0][1];
                lhs[i][j][k1][0][0][2] = -tmp2 * fjac[i][j][k1 - 1][0][2] - tmp1 * njac[i][j][k1 - 1][0][2];
                lhs[i][j][k1][0][0][3] = -tmp2 * fjac[i][j][k1 - 1][0][3] - tmp1 * njac[i][j][k1 - 1][0][3];
                lhs[i][j][k1][0][0][4] = -tmp2 * fjac[i][j][k1 - 1][0][4] - tmp1 * njac[i][j][k1 - 1][0][4];
                lhs[i][j][k1][0][1][0] = -tmp2 * fjac[i][j][k1 - 1][1][0] - tmp1 * njac[i][j][k1 - 1][1][0];
                lhs[i][j][k1][0][1][1] = -tmp2 * fjac[i][j][k1 - 1][1][1] - tmp1 * njac[i][j][k1 - 1][1][1] - tmp1 * dz2;
                lhs[i][j][k1][0][1][2] = -tmp2 * fjac[i][j][k1 - 1][1][2] - tmp1 * njac[i][j][k1 - 1][1][2];
                lhs[i][j][k1][0][1][3] = -tmp2 * fjac[i][j][k1 - 1][1][3] - tmp1 * njac[i][j][k1 - 1][1][3];
                lhs[i][j][k1][0][1][4] = -tmp2 * fjac[i][j][k1 - 1][1][4] - tmp1 * njac[i][j][k1 - 1][1][4];
                lhs[i][j][k1][0][2][0] = -tmp2 * fjac[i][j][k1 - 1][2][0] - tmp1 * njac[i][j][k1 - 1][2][0];
                lhs[i][j][k1][0][2][1] = -tmp2 * fjac[i][j][k1 - 1][2][1] - tmp1 * njac[i][j][k1 - 1][2][1];
                lhs[i][j][k1][0][2][2] = -tmp2 * fjac[i][j][k1 - 1][2][2] - tmp1 * njac[i][j][k1 - 1][2][2] - tmp1 * dz3;
                lhs[i][j][k1][0][2][3] = -tmp2 * fjac[i][j][k1 - 1][2][3] - tmp1 * njac[i][j][k1 - 1][2][3];
                lhs[i][j][k1][0][2][4] = -tmp2 * fjac[i][j][k1 - 1][2][4] - tmp1 * njac[i][j][k1 - 1][2][4];
                lhs[i][j][k1][0][3][0] = -tmp2 * fjac[i][j][k1 - 1][3][0] - tmp1 * njac[i][j][k1 - 1][3][0];
                lhs[i][j][k1][0][3][1] = -tmp2 * fjac[i][j][k1 - 1][3][1] - tmp1 * njac[i][j][k1 - 1][3][1];
                lhs[i][j][k1][0][3][2] = -tmp2 * fjac[i][j][k1 - 1][3][2] - tmp1 * njac[i][j][k1 - 1][3][2];
                lhs[i][j][k1][0][3][3] = -tmp2 * fjac[i][j][k1 - 1][3][3] - tmp1 * njac[i][j][k1 - 1][3][3] - tmp1 * dz4;
                lhs[i][j][k1][0][3][4] = -tmp2 * fjac[i][j][k1 - 1][3][4] - tmp1 * njac[i][j][k1 - 1][3][4];
                lhs[i][j][k1][0][4][0] = -tmp2 * fjac[i][j][k1 - 1][4][0] - tmp1 * njac[i][j][k1 - 1][4][0];
                lhs[i][j][k1][0][4][1] = -tmp2 * fjac[i][j][k1 - 1][4][1] - tmp1 * njac[i][j][k1 - 1][4][1];
                lhs[i][j][k1][0][4][2] = -tmp2 * fjac[i][j][k1 - 1][4][2] - tmp1 * njac[i][j][k1 - 1][4][2];
                lhs[i][j][k1][0][4][3] = -tmp2 * fjac[i][j][k1 - 1][4][3] - tmp1 * njac[i][j][k1 - 1][4][3];
                lhs[i][j][k1][0][4][4] = -tmp2 * fjac[i][j][k1 - 1][4][4] - tmp1 * njac[i][j][k1 - 1][4][4] - tmp1 * dz5;

                lhs[i][j][k1][1][0][0] = 1. + tmp1 * 2. * njac[i][j][k1][0][0] + tmp1 * 2. * dz1;
                lhs[i][j][k1][1][0][1] = tmp1 * 2. * njac[i][j][k1][0][1];
                lhs[i][j][k1][1][0][2] = tmp1 * 2. * njac[i][j][k1][0][2];
                lhs[i][j][k1][1][0][3] = tmp1 * 2. * njac[i][j][k1][0][3];
                lhs[i][j][k1][1][0][4] = tmp1 * 2. * njac[i][j][k1][0][4];
                lhs[i][j][k1][1][1][0] = tmp1 * 2. * njac[i][j][k1][1][0];
                lhs[i][j][k1][1][1][1] = 1. + tmp1 * 2. * njac[i][j][k1][1][1] + tmp1 * 2. * dz2;
                lhs[i][j][k1][1][1][2] = tmp1 * 2. * njac[i][j][k1][1][2];
                lhs[i][j][k1][1][1][3] = tmp1 * 2. * njac[i][j][k1][1][3];
                lhs[i][j][k1][1][1][4] = tmp1 * 2. * njac[i][j][k1][1][4];
                lhs[i][j][k1][1][2][0] = tmp1 * 2. * njac[i][j][k1][2][0];
                lhs[i][j][k1][1][2][1] = tmp1 * 2. * njac[i][j][k1][2][1];
                lhs[i][j][k1][1][2][2] = 1. + tmp1 * 2. * njac[i][j][k1][2][2] + tmp1 * 2. * dz3;
                lhs[i][j][k1][1][2][3] = tmp1 * 2. * njac[i][j][k1][2][3];
                lhs[i][j][k1][1][2][4] = tmp1 * 2. * njac[i][j][k1][2][4];
                lhs[i][j][k1][1][3][0] = tmp1 * 2. * njac[i][j][k1][3][0];
                lhs[i][j][k1][1][3][1] = tmp1 * 2. * njac[i][j][k1][3][1];
                lhs[i][j][k1][1][3][2] = tmp1 * 2. * njac[i][j][k1][3][2];
                lhs[i][j][k1][1][3][3] = 1. + tmp1 * 2. * njac[i][j][k1][3][3] + tmp1 * 2. * dz4;
                lhs[i][j][k1][1][3][4] = tmp1 * 2. * njac[i][j][k1][3][4];
                lhs[i][j][k1][1][4][0] = tmp1 * 2. * njac[i][j][k1][4][0];
                lhs[i][j][k1][1][4][1] = tmp1 * 2. * njac[i][j][k1][4][1];
                lhs[i][j][k1][1][4][2] = tmp1 * 2. * njac[i][j][k1][4][2];
                lhs[i][j][k1][1][4][3] = tmp1 * 2. * njac[i][j][k1][4][3];
                lhs[i][j][k1][1][4][4] = 1. + tmp1 * 2. * njac[i][j][k1][4][4] + tmp1 * 2. * dz5;

                lhs[i][j][k1][2][0][0] = tmp2 * fjac[i][j][k1 + 1][0][0] - tmp1 * njac[i][j][k1 + 1][0][0] - tmp1 * dz1;
                lhs[i][j][k1][2][0][1] = tmp2 * fjac[i][j][k1 + 1][0][1] - tmp1 * njac[i][j][k1 + 1][0][1];
                lhs[i][j][k1][2][0][2] = tmp2 * fjac[i][j][k1 + 1][0][2] - tmp1 * njac[i][j][k1 + 1][0][2];
                lhs[i][j][k1][2][0][3] = tmp2 * fjac[i][j][k1 + 1][0][3] - tmp1 * njac[i][j][k1 + 1][0][3];
                lhs[i][j][k1][2][0][4] = tmp2 * fjac[i][j][k1 + 1][0][4] - tmp1 * njac[i][j][k1 + 1][0][4];
                lhs[i][j][k1][2][1][0] = tmp2 * fjac[i][j][k1 + 1][1][0] - tmp1 * njac[i][j][k1 + 1][1][0];
                lhs[i][j][k1][2][1][1] = tmp2 * fjac[i][j][k1 + 1][1][1] - tmp1 * njac[i][j][k1 + 1][1][1] - tmp1 * dz2;
                lhs[i][j][k1][2][1][2] = tmp2 * fjac[i][j][k1 + 1][1][2] - tmp1 * njac[i][j][k1 + 1][1][2];
                lhs[i][j][k1][2][1][3] = tmp2 * fjac[i][j][k1 + 1][1][3] - tmp1 * njac[i][j][k1 + 1][1][3];
                lhs[i][j][k1][2][1][4] = tmp2 * fjac[i][j][k1 + 1][1][4] - tmp1 * njac[i][j][k1 + 1][1][4];
                lhs[i][j][k1][2][2][0] = tmp2 * fjac[i][j][k1 + 1][2][0] - tmp1 * njac[i][j][k1 + 1][2][0];
                lhs[i][j][k1][2][2][1] = tmp2 * fjac[i][j][k1 + 1][2][1] - tmp1 * njac[i][j][k1 + 1][2][1];
                lhs[i][j][k1][2][2][2] = tmp2 * fjac[i][j][k1 + 1][2][2] - tmp1 * njac[i][j][k1 + 1][2][2] - tmp1 * dz3;
                lhs[i][j][k1][2][2][3] = tmp2 * fjac[i][j][k1 + 1][2][3] - tmp1 * njac[i][j][k1 + 1][2][3];
                lhs[i][j][k1][2][2][4] = tmp2 * fjac[i][j][k1 + 1][2][4] - tmp1 * njac[i][j][k1 + 1][2][4];
                lhs[i][j][k1][2][3][0] = tmp2 * fjac[i][j][k1 + 1][3][0] - tmp1 * njac[i][j][k1 + 1][3][0];
                lhs[i][j][k1][2][3][1] = tmp2 * fjac[i][j][k1 + 1][3][1] - tmp1 * njac[i][j][k1 + 1][3][1];
                lhs[i][j][k1][2][3][2] = tmp2 * fjac[i][j][k1 + 1][3][2] - tmp1 * njac[i][j][k1 + 1][3][2];
                lhs[i][j][k1][2][3][3] = tmp2 * fjac[i][j][k1 + 1][3][3] - tmp1 * njac[i][j][k1 + 1][3][3] - tmp1 * dz4;
                lhs[i][j][k1][2][3][4] = tmp2 * fjac[i][j][k1 + 1][3][4] - tmp1 * njac[i][j][k1 + 1][3][4];
                lhs[i][j][k1][2][4][0] = tmp2 * fjac[i][j][k1 + 1][4][0] - tmp1 * njac[i][j][k1 + 1][4][0];
                lhs[i][j][k1][2][4][1] = tmp2 * fjac[i][j][k1 + 1][4][1] - tmp1 * njac[i][j][k1 + 1][4][1];
                lhs[i][j][k1][2][4][2] = tmp2 * fjac[i][j][k1 + 1][4][2] - tmp1 * njac[i][j][k1 + 1][4][2];
                lhs[i][j][k1][2][4][3] = tmp2 * fjac[i][j][k1 + 1][4][3] - tmp1 * njac[i][j][k1 + 1][4][3];
                lhs[i][j][k1][2][4][4] = tmp2 * fjac[i][j][k1 + 1][4][4] - tmp1 * njac[i][j][k1 + 1][4][4] - tmp1 * dz5;

                // Second k index update (k+1)
                int k2 = k + 1;
                lhs[i][j][k2][0][0][0] = -tmp2 * fjac[i][j][k2 - 1][0][0] - tmp1 * njac[i][j][k2 - 1][0][0] - tmp1 * dz1;
                lhs[i][j][k2][0][0][1] = -tmp2 * fjac[i][j][k2 - 1][0][1] - tmp1 * njac[i][j][k2 - 1][0][1];
                lhs[i][j][k2][0][0][2] = -tmp2 * fjac[i][j][k2 - 1][0][2] - tmp1 * njac[i][j][k2 - 1][0][2];
                lhs[i][j][k2][0][0][3] = -tmp2 * fjac[i][j][k2 - 1][0][3] - tmp1 * njac[i][j][k2 - 1][0][3];
                lhs[i][j][k2][0][0][4] = -tmp2 * fjac[i][j][k2 - 1][0][4] - tmp1 * njac[i][j][k2 - 1][0][4];
                lhs[i][j][k2][0][1][0] = -tmp2 * fjac[i][j][k2 - 1][1][0] - tmp1 * njac[i][j][k2 - 1][1][0];
                lhs[i][j][k2][0][1][1] = -tmp2 * fjac[i][j][k2 - 1][1][1] - tmp1 * njac[i][j][k2 - 1][1][1] - tmp1 * dz2;
                lhs[i][j][k2][0][1][2] = -tmp2 * fjac[i][j][k2 - 1][1][2] - tmp1 * njac[i][j][k2 - 1][1][2];
                lhs[i][j][k2][0][1][3] = -tmp2 * fjac[i][j][k2 - 1][1][3] - tmp1 * njac[i][j][k2 - 1][1][3];
                lhs[i][j][k2][0][1][4] = -tmp2 * fjac[i][j][k2 - 1][1][4] - tmp1 * njac[i][j][k2 - 1][1][4];
                lhs[i][j][k2][0][2][0] = -tmp2 * fjac[i][j][k2 - 1][2][0] - tmp1 * njac[i][j][k2 - 1][2][0];
                lhs[i][j][k2][0][2][1] = -tmp2 * fjac[i][j][k2 - 1][2][1] - tmp1 * njac[i][j][k2 - 1][2][1];
                lhs[i][j][k2][0][2][2] = -tmp2 * fjac[i][j][k2 - 1][2][2] - tmp1 * njac[i][j][k2 - 1][2][2] - tmp1 * dz3;
                lhs[i][j][k2][0][2][3] = -tmp2 * fjac[i][j][k2 - 1][2][3] - tmp1 * njac[i][j][k2 - 1][2][3];
                lhs[i][j][k2][0][2][4] = -tmp2 * fjac[i][j][k2 - 1][2][4] - tmp1 * njac[i][j][k2 - 1][2][4];
                lhs[i][j][k2][0][3][0] = -tmp2 * fjac[i][j][k2 - 1][3][0] - tmp1 * njac[i][j][k2 - 1][3][0];
                lhs[i][j][k2][0][3][1] = -tmp2 * fjac[i][j][k2 - 1][3][1] - tmp1 * njac[i][j][k2 - 1][3][1];
                lhs[i][j][k2][0][3][2] = -tmp2 * fjac[i][j][k2 - 1][3][2] - tmp1 * njac[i][j][k2 - 1][3][2];
                lhs[i][j][k2][0][3][3] = -tmp2 * fjac[i][j][k2 - 1][3][3] - tmp1 * njac[i][j][k2 - 1][3][3] - tmp1 * dz4;
                lhs[i][j][k2][0][3][4] = -tmp2 * fjac[i][j][k2 - 1][3][4] - tmp1 * njac[i][j][k2 - 1][3][4];
                lhs[i][j][k2][0][4][0] = -tmp2 * fjac[i][j][k2 - 1][4][0] - tmp1 * njac[i][j][k2 - 1][4][0];
                lhs[i][j][k2][0][4][1] = -tmp2 * fjac[i][j][k2 - 1][4][1] - tmp1 * njac[i][j][k2 - 1][4][1];
                lhs[i][j][k2][0][4][2] = -tmp2 * fjac[i][j][k2 - 1][4][2] - tmp1 * njac[i][j][k2 - 1][4][2];
                lhs[i][j][k2][0][4][3] = -tmp2 * fjac[i][j][k2 - 1][4][3] - tmp1 * njac[i][j][k2 - 1][4][3];
                lhs[i][j][k2][0][4][4] = -tmp2 * fjac[i][j][k2 - 1][4][4] - tmp1 * njac[i][j][k2 - 1][4][4] - tmp1 * dz5;

                lhs[i][j][k2][1][0][0] = 1. + tmp1 * 2. * njac[i][j][k2][0][0] + tmp1 * 2. * dz1;
                lhs[i][j][k2][1][0][1] = tmp1 * 2. * njac[i][j][k2][0][1];
                lhs[i][j][k2][1][0][2] = tmp1 * 2. * njac[i][j][k2][0][2];
                lhs[i][j][k2][1][0][3] = tmp1 * 2. * njac[i][j][k2][0][3];
                lhs[i][j][k2][1][0][4] = tmp1 * 2. * njac[i][j][k2][0][4];
                lhs[i][j][k2][1][1][0] = tmp1 * 2. * njac[i][j][k2][1][0];
                lhs[i][j][k2][1][1][1] = 1. + tmp1 * 2. * njac[i][j][k2][1][1] + tmp1 * 2. * dz2;
                lhs[i][j][k2][1][1][2] = tmp1 * 2. * njac[i][j][k2][1][2];
                lhs[i][j][k2][1][1][3] = tmp1 * 2. * njac[i][j][k2][1][3];
                lhs[i][j][k2][1][1][4] = tmp1 * 2. * njac[i][j][k2][1][4];
                lhs[i][j][k2][1][2][0] = tmp1 * 2. * njac[i][j][k2][2][0];
                lhs[i][j][k2][1][2][1] = tmp1 * 2. * njac[i][j][k2][2][1];
                lhs[i][j][k2][1][2][2] = 1. + tmp1 * 2. * njac[i][j][k2][2][2] + tmp1 * 2. * dz3;
                lhs[i][j][k2][1][2][3] = tmp1 * 2. * njac[i][j][k2][2][3];
                lhs[i][j][k2][1][2][4] = tmp1 * 2. * njac[i][j][k2][2][4];
                lhs[i][j][k2][1][3][0] = tmp1 * 2. * njac[i][j][k2][3][0];
                lhs[i][j][k2][1][3][1] = tmp1 * 2. * njac[i][j][k2][3][1];
                lhs[i][j][k2][1][3][2] = tmp1 * 2. * njac[i][j][k2][3][2];
                lhs[i][j][k2][1][3][3] = 1. + tmp1 * 2. * njac[i][j][k2][3][3] + tmp1 * 2. * dz4;
                lhs[i][j][k2][1][3][4] = tmp1 * 2. * njac[i][j][k2][3][4];
                lhs[i][j][k2][1][4][0] = tmp1 * 2. * njac[i][j][k2][4][0];
                lhs[i][j][k2][1][4][1] = tmp1 * 2. * njac[i][j][k2][4][1];
                lhs[i][j][k2][1][4][2] = tmp1 * 2. * njac[i][j][k2][4][2];
                lhs[i][j][k2][1][4][3] = tmp1 * 2. * njac[i][j][k2][4][3];
                lhs[i][j][k2][1][4][4] = 1. + tmp1 * 2. * njac[i][j][k2][4][4] + tmp1 * 2. * dz5;

                lhs[i][j][k2][2][0][0] = tmp2 * fjac[i][j][k2 + 1][0][0] - tmp1 * njac[i][j][k2 + 1][0][0] - tmp1 * dz1;
                lhs[i][j][k2][2][0][1] = tmp2 * fjac[i][j][k2 + 1][0][1] - tmp1 * njac[i][j][k2 + 1][0][1];
                lhs[i][j][k2][2][0][2] = tmp2 * fjac[i][j][k2 + 1][0][2] - tmp1 * njac[i][j][k2 + 1][0][2];
                lhs[i][j][k2][2][0][3] = tmp2 * fjac[i][j][k2 + 1][0][3] - tmp1 * njac[i][j][k2 + 1][0][3];
                lhs[i][j][k2][2][0][4] = tmp2 * fjac[i][j][k2 + 1][0][4] - tmp1 * njac[i][j][k2 + 1][0][4];
                lhs[i][j][k2][2][1][0] = tmp2 * fjac[i][j][k2 + 1][1][0] - tmp1 * njac[i][j][k2 + 1][1][0];
                lhs[i][j][k2][2][1][1] = tmp2 * fjac[i][j][k2 + 1][1][1] - tmp1 * njac[i][j][k2 + 1][1][1] - tmp1 * dz2;
                lhs[i][j][k2][2][1][2] = tmp2 * fjac[i][j][k2 + 1][1][2] - tmp1 * njac[i][j][k2 + 1][1][2];
                lhs[i][j][k2][2][1][3] = tmp2 * fjac[i][j][k2 + 1][1][3] - tmp1 * njac[i][j][k2 + 1][1][3];
                lhs[i][j][k2][2][1][4] = tmp2 * fjac[i][j][k2 + 1][1][4] - tmp1 * njac[i][j][k2 + 1][1][4];
                lhs[i][j][k2][2][2][0] = tmp2 * fjac[i][j][k2 + 1][2][0] - tmp1 * njac[i][j][k2 + 1][2][0];
                lhs[i][j][k2][2][2][1] = tmp2 * fjac[i][j][k2 + 1][2][1] - tmp1 * njac[i][j][k2 + 1][2][1];
                lhs[i][j][k2][2][2][2] = tmp2 * fjac[i][j][k2 + 1][2][2] - tmp1 * njac[i][j][k2 + 1][2][2] - tmp1 * dz3;
                lhs[i][j][k2][2][2][3] = tmp2 * fjac[i][j][k2 + 1][2][3] - tmp1 * njac[i][j][k2 + 1][2][3];
                lhs[i][j][k2][2][2][4] = tmp2 * fjac[i][j][k2 + 1][2][4] - tmp1 * njac[i][j][k2 + 1][2][4];
                lhs[i][j][k2][2][3][0] = tmp2 * fjac[i][j][k2 + 1][3][0] - tmp1 * njac[i][j][k2 + 1][3][0];
                lhs[i][j][k2][2][3][1] = tmp2 * fjac[i][j][k2 + 1][3][1] - tmp1 * njac[i][j][k2 + 1][3][1];
                lhs[i][j][k2][2][3][2] = tmp2 * fjac[i][j][k2 + 1][3][2] - tmp1 * njac[i][j][k2 + 1][3][2];
                lhs[i][j][k2][2][3][3] = tmp2 * fjac[i][j][k2 + 1][3][3] - tmp1 * njac[i][j][k2 + 1][3][3] - tmp1 * dz4;
                lhs[i][j][k2][2][3][4] = tmp2 * fjac[i][j][k2 + 1][3][4] - tmp1 * njac[i][j][k2 + 1][3][4];
                lhs[i][j][k2][2][4][0] = tmp2 * fjac[i][j][k2 + 1][4][0] - tmp1 * njac[i][j][k2 + 1][4][0];
                lhs[i][j][k2][2][4][1] = tmp2 * fjac[i][j][k2 + 1][4][1] - tmp1 * njac[i][j][k2 + 1][4][1];
                lhs[i][j][k2][2][4][2] = tmp2 * fjac[i][j][k2 + 1][4][2] - tmp1 * njac[i][j][k2 + 1][4][2];
                lhs[i][j][k2][2][4][3] = tmp2 * fjac[i][j][k2 + 1][4][3] - tmp1 * njac[i][j][k2 + 1][4][3];
                lhs[i][j][k2][2][4][4] = tmp2 * fjac[i][j][k2 + 1][4][4] - tmp1 * njac[i][j][k2 + 1][4][4] - tmp1 * dz5;
            }
        }
    }
}
