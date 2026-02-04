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
                int ii, jj;
                for (ii = 0; ii < 5; ii++) {
                    for (jj = 0; jj < 5; jj++) {
                        double fj = fjac[i][j-1][k][ii][jj];
                        double nj = njac[i][j-1][k][ii][jj];
                        lhs[i][j][k][0][ii][jj] = -tmp2 * fj - tmp1 * nj;
                        if (ii == jj) {
                            if (ii == 0) lhs[i][j][k][0][ii][jj] -= tmp1 * dy1;
                            else if (ii == 1) lhs[i][j][k][0][ii][jj] -= tmp1 * dy2;
                            else if (ii == 2) lhs[i][j][k][0][ii][jj] -= tmp1 * dy3;
                            else if (ii == 3) lhs[i][j][k][0][ii][jj] -= tmp1 * dy4;
                            else if (ii == 4) lhs[i][j][k][0][ii][jj] -= tmp1 * dy5;
                        }
                    }
                }
                for (ii = 0; ii < 5; ii++) {
                    for (jj = 0; jj < 5; jj++) {
                        double nj = njac[i][j][k][ii][jj];
                        lhs[i][j][k][1][ii][jj] = tmp1 * 2.0 * nj;
                        if (ii == jj) {
                            lhs[i][j][k][1][ii][jj] += 1.0;
                            if (ii == 0) lhs[i][j][k][1][ii][jj] += tmp1 * 2.0 * dy1;
                            else if (ii == 1) lhs[i][j][k][1][ii][jj] += tmp1 * 2.0 * dy2;
                            else if (ii == 2) lhs[i][j][k][1][ii][jj] += tmp1 * 2.0 * dy3;
                            else if (ii == 3) lhs[i][j][k][1][ii][jj] += tmp1 * 2.0 * dy4;
                            else if (ii == 4) lhs[i][j][k][1][ii][jj] += tmp1 * 2.0 * dy5;
                        }
                    }
                }
                for (ii = 0; ii < 5; ii++) {
                    for (jj = 0; jj < 5; jj++) {
                        double fj = fjac[i][j+1][k][ii][jj];
                        double nj = njac[i][j+1][k][ii][jj];
                        lhs[i][j][k][2][ii][jj] = tmp2 * fj - tmp1 * nj;
                        if (ii == jj) {
                            if (ii == 0) lhs[i][j][k][2][ii][jj] -= tmp1 * dy1;
                            else if (ii == 1) lhs[i][j][k][2][ii][jj] -= tmp1 * dy2;
                            else if (ii == 2) lhs[i][j][k][2][ii][jj] -= tmp1 * dy3;
                            else if (ii == 3) lhs[i][j][k][2][ii][jj] -= tmp1 * dy4;
                            else if (ii == 4) lhs[i][j][k][2][ii][jj] -= tmp1 * dy5;
                        }
                    }
                }
            }
        }
    }
}
