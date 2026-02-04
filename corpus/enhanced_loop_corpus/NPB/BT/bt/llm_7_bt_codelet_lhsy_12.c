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
            for (k = 1; k < grid_points[2] - 1; k += 2) {  // Stride-2 in k-loop to increase reuse per access
                tmp1 = dt * ty1;
                tmp2 = dt * ty2;

                // Unroll k-loop partially by handling two k-values (if safe)
                int k2 = k + 1;
                if (k2 >= grid_points[2] - 1) k2 = k; // Avoid out-of-bounds

                // Process k
                for (int ii = 0; ii < 3; ii++) {
                    for (int jj = 0; jj < 5; jj++) {
                        for (int mm = 0; mm < 5; mm++) {
                            double coeff = (ii == 0) ? (-tmp2 * fjac[i][j-1][k][jj][mm] - tmp1 * njac[i][j-1][k][jj][mm]) :
                                          (ii == 1) ? (1.0 + 2.0 * tmp1 * njac[i][j][k][jj][mm]) :
                                                      (tmp2 * fjac[i][j+1][k][jj][mm] - tmp1 * njac[i][j+1][k][jj][mm]);

                            if (ii == 0 && jj == mm) {
                                if (jj == 0) coeff -= tmp1 * dy1;
                                else if (jj == 1) coeff -= tmp1 * dy2;
                                else if (jj == 2) coeff -= tmp1 * dy3;
                                else if (jj == 3) coeff -= tmp1 * dy4;
                                else if (jj == 4) coeff -= tmp1 * dy5;
                            } else if (ii == 1 && jj == mm) {
                                if (jj == 0) coeff += 2.0 * tmp1 * dy1;
                                else if (jj == 1) coeff += 2.0 * tmp1 * dy2;
                                else if (jj == 2) coeff += 2.0 * tmp1 * dy3;
                                else if (jj == 3) coeff += 2.0 * tmp1 * dy4;
                                else if (jj == 4) coeff += 2.0 * tmp1 * dy5;
                            } else if (ii == 2 && jj == mm) {
                                if (jj == 0) coeff -= tmp1 * dy1;
                                else if (jj == 1) coeff -= tmp1 * dy2;
                                else if (jj == 2) coeff -= tmp1 * dy3;
                                else if (jj == 3) coeff -= tmp1 * dy4;
                                else if (jj == 4) coeff -= tmp1 * dy5;
                            }

                            lhs[i][j][k][ii][jj][mm] = coeff;
                        }
                    }
                }

                // Process k2 (second iteration of unrolled k)
                for (int ii = 0; ii < 3; ii++) {
                    for (int jj = 0; jj < 5; jj++) {
                        for (int mm = 0; mm < 5; mm++) {
                            double coeff = (ii == 0) ? (-tmp2 * fjac[i][j-1][k2][jj][mm] - tmp1 * njac[i][j-1][k2][jj][mm]) :
                                          (ii == 1) ? (1.0 + 2.0 * tmp1 * njac[i][j][k2][jj][mm]) :
                                                      (tmp2 * fjac[i][j+1][k2][jj][mm] - tmp1 * njac[i][j+1][k2][jj][mm]);

                            if (ii == 0 && jj == mm) {
                                if (jj == 0) coeff -= tmp1 * dy1;
                                else if (jj == 1) coeff -= tmp1 * dy2;
                                else if (jj == 2) coeff -= tmp1 * dy3;
                                else if (jj == 3) coeff -= tmp1 * dy4;
                                else if (jj == 4) coeff -= tmp1 * dy5;
                            } else if (ii == 1 && jj == mm) {
                                if (jj == 0) coeff += 2.0 * tmp1 * dy1;
                                else if (jj == 1) coeff += 2.0 * tmp1 * dy2;
                                else if (jj == 2) coeff += 2.0 * tmp1 * dy3;
                                else if (jj == 3) coeff += 2.0 * tmp1 * dy4;
                                else if (jj == 4) coeff += 2.0 * tmp1 * dy5;
                            } else if (ii == 2 && jj == mm) {
                                if (jj == 0) coeff -= tmp1 * dy1;
                                else if (jj == 1) coeff -= tmp1 * dy2;
                                else if (jj == 2) coeff -= tmp1 * dy3;
                                else if (jj == 3) coeff -= tmp1 * dy4;
                                else if (jj == 4) coeff -= tmp1 * dy5;
                            }

                            lhs[i][j][k2][ii][jj][mm] = coeff;
                        }
                    }
                }
            }
        }
    }
}
