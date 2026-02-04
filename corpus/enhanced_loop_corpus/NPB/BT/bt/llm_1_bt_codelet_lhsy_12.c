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
    tmp1 = dt * ty1;
    tmp2 = dt * ty2;
    for (i = 1; i < grid_points[0] - 1; i++) {
        for (j = 1; j < grid_points[1] - 1; j++) {
            for (k = 1; k < grid_points[2] - 1; k++) {
                // Unrolling the [0][*][*] block with partial fusion
                lhs[i][j][k][0][0][0] = -tmp2 * fjac[i][j-1][k][0][0] - tmp1 * njac[i][j-1][k][0][0] - tmp1 * dy1;
                lhs[i][j][k][0][1][1] = -tmp2 * fjac[i][j-1][k][1][1] - tmp1 * njac[i][j-1][k][1][1] - tmp1 * dy2;
                lhs[i][j][k][0][2][2] = -tmp2 * fjac[i][j-1][k][2][2] - tmp1 * njac[i][j-1][k][2][2] - tmp1 * dy3;
                lhs[i][j][k][0][3][3] = -tmp2 * fjac[i][j-1][k][3][3] - tmp1 * njac[i][j-1][k][3][3] - tmp1 * dy4;
                lhs[i][j][k][0][4][4] = -tmp2 * fjac[i][j-1][k][4][4] - tmp1 * njac[i][j-1][k][4][4] - tmp1 * dy5;

                // Fill off-diagonal elements of [0]
                for (int r = 0; r < 5; r++) {
                    for (int s = 0; s < 5; s++) {
                        if (r != s) {
                            lhs[i][j][k][0][r][s] = -tmp2 * fjac[i][j-1][k][r][s] - tmp1 * njac[i][j-1][k][r][s];
                        }
                    }
                }

                // Block [1]: diagonal has identity and scaling
                for (int r = 0; r < 5; r++) {
                    for (int s = 0; s < 5; s++) {
                        lhs[i][j][k][1][r][s] = tmp1 * 2.0 * njac[i][j][k][r][s];
                        if (r == s) {
                            lhs[i][j][k][1][r][s] += 1.0;
                            if (r == 0) lhs[i][j][k][1][r][s] += tmp1 * 2.0 * dy1;
                            else if (r == 1) lhs[i][j][k][1][r][s] += tmp1 * 2.0 * dy2;
                            else if (r == 2) lhs[i][j][k][1][r][s] += tmp1 * 2.0 * dy3;
                            else if (r == 3) lhs[i][j][k][1][r][s] += tmp1 * 2.0 * dy4;
                            else if (r == 4) lhs[i][j][k][1][r][s] += tmp1 * 2.0 * dy5;
                        }
                    }
                }

                // Block [2]: similar to [0], but with j+1 and positive fjac
                lhs[i][j][k][2][0][0] = tmp2 * fjac[i][j+1][k][0][0] - tmp1 * njac[i][j+1][k][0][0] - tmp1 * dy1;
                lhs[i][j][k][2][1][1] = tmp2 * fjac[i][j+1][k][1][1] - tmp1 * njac[i][j+1][k][1][1] - tmp1 * dy2;
                lhs[i][j][k][2][2][2] = tmp2 * fjac[i][j+1][k][2][2] - tmp1 * njac[i][j+1][k][2][2] - tmp1 * dy3;
                lhs[i][j][k][2][3][3] = tmp2 * fjac[i][j+1][k][3][3] - tmp1 * njac[i][j+1][k][3][3] - tmp1 * dy4;
                lhs[i][j][k][2][4][4] = tmp2 * fjac[i][j+1][k][4][4] - tmp1 * njac[i][j+1][k][4][4] - tmp1 * dy5;

                for (int r = 0; r < 5; r++) {
                    for (int s = 0; s < 5; s++) {
                        if (r != s) {
                            lhs[i][j][k][2][r][s] = tmp2 * fjac[i][j+1][k][r][s] - tmp1 * njac[i][j+1][k][r][s];
                        }
                    }
                }
            }
        }
    }
}
