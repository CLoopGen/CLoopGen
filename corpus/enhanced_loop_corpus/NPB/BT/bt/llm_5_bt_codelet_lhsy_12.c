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
            tmp1 = dt * ty1;
            tmp2 = dt * ty2;

            double fj, nj;
            int offset_jm1 = j - 1;
            int offset_jp1 = j + 1;

            for (int m = 0; m < 5; m++) {
                for (int n = 0; n < 5; n++) {
                    fj = fjac[i][offset_jm1][k][m][n];
                    nj = njac[i][offset_jm1][k][m][n];
                    lhs[i][j][k][0][m][n] = -tmp2 * fj - tmp1 * nj;
                    if (m == n) {
                        if (m == 0) lhs[i][j][k][0][m][n] -= tmp1 * dy1;
                        else if (m == 1) lhs[i][j][k][0][m][n] -= tmp1 * dy2;
                        else if (m == 2) lhs[i][j][k][0][m][n] -= tmp1 * dy3;
                        else if (m == 3) lhs[i][j][k][0][m][n] -= tmp1 * dy4;
                        else if (m == 4) lhs[i][j][k][0][m][n] -= tmp1 * dy5;
                    }
                }
            }

            for (int m = 0; m < 5; m++) {
                for (int n = 0; n < 5; n++) {
                    nj = njac[i][j][k][m][n];
                    lhs[i][j][k][1][m][n] = tmp1 * 2.0 * nj;
                    if (m == n) {
                        lhs[i][j][k][1][m][n] += 1.0;
                        if (m == 0) lhs[i][j][k][1][m][n] += tmp1 * 2.0 * dy1;
                        else if (m == 1) lhs[i][j][k][1][m][n] += tmp1 * 2.0 * dy2;
                        else if (m == 2) lhs[i][j][k][1][m][n] += tmp1 * 2.0 * dy3;
                        else if (m == 3) lhs[i][j][k][1][m][n] += tmp1 * 2.0 * dy4;
                        else if (m == 4) lhs[i][j][k][1][m][n] += tmp1 * 2.0 * dy5;
                    }
                }
            }

            for (int m = 0; m < 5; m++) {
                for (int n = 0; n < 5; n++) {
                    fj = fjac[i][offset_jp1][k][m][n];
                    nj = njac[i][offset_jp1][k][m][n];
                    lhs[i][j][k][2][m][n] = tmp2 * fj - tmp1 * nj;
                    if (m == n) {
                        if (m == 0) lhs[i][j][k][2][m][n] -= tmp1 * dy1;
                        else if (m == 1) lhs[i][j][k][2][m][n] -= tmp1 * dy2;
                        else if (m == 2) lhs[i][j][k][2][m][n] -= tmp1 * dy3;
                        else if (m == 3) lhs[i][j][k][2][m][n] -= tmp1 * dy4;
                        else if (m == 4) lhs[i][j][k][2][m][n] -= tmp1 * dy5;
                    }
                }
            }
        }
    }
}
}
