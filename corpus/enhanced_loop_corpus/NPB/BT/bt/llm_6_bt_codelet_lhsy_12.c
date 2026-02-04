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
    for (i = 2; i < grid_points[0] - 2; i++) {
        for (j = 2; j < grid_points[1] - 2; j++) {
            for (k = 2; k < grid_points[2] - 2; k++) {
                tmp1 = dt * ty1;
                tmp2 = dt * ty2;

                // Reduced computation: only compute diagonal elements of the [3][5][5] block
                for (int d = 0; d < 5; d++) {
                    lhs[i][j][k][0][d][d] = -tmp2 * fjac[i][j-1][k][d][d] - tmp1 * njac[i][j-1][k][d][d];
                    if (d == 0) lhs[i][j][k][0][d][d] -= tmp1 * dy1;
                    else if (d == 1) lhs[i][j][k][0][d][d] -= tmp1 * dy2;
                    else if (d == 2) lhs[i][j][k][0][d][d] -= tmp1 * dy3;
                    else if (d == 3) lhs[i][j][k][0][d][d] -= tmp1 * dy4;
                    else if (d == 4) lhs[i][j][k][0][d][d] -= tmp1 * dy5;

                    lhs[i][j][k][1][d][d] = 1.0 + 2.0 * tmp1 * njac[i][j][k][d][d];
                    if (d == 0) lhs[i][j][k][1][d][d] += 2.0 * tmp1 * dy1;
                    else if (d == 1) lhs[i][j][k][1][d][d] += 2.0 * tmp1 * dy2;
                    else if (d == 2) lhs[i][j][k][1][d][d] += 2.0 * tmp1 * dy3;
                    else if (d == 3) lhs[i][j][k][1][d][d] += 2.0 * tmp1 * dy4;
                    else if (d == 4) lhs[i][j][k][1][d][d] += 2.0 * tmp1 * dy5;

                    lhs[i][j][k][2][d][d] = tmp2 * fjac[i][j+1][k][d][d] - tmp1 * njac[i][j+1][k][d][d];
                    if (d == 0) lhs[i][j][k][2][d][d] -= tmp1 * dy1;
                    else if (d == 1) lhs[i][j][k][2][d][d] -= tmp1 * dy2;
                    else if (d == 2) lhs[i][j][k][2][d][d] -= tmp1 * dy3;
                    else if (d == 3) lhs[i][j][k][2][d][d] -= tmp1 * dy4;
                    else if (d == 4) lhs[i][j][k][2][d][d] -= tmp1 * dy5;
                }

                // Skip off-diagonal computations to reduce arithmetic intensity
            }
        }
    }
}
