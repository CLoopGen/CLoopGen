#include <stdio.h>

extern  int grid_points[3];
extern  double dy1;
extern  double dy3;
extern  double dy5;
extern  double dymax;
extern  double c1c5;
extern  double c3c4;
extern  double dtty1;
extern  double dtty2;
extern  double c2dtty1;
extern  double con43;
extern  double vs[65][65][65];
extern  double rho_i[65][65][65];
extern  double lhs[15][65][65][65];
extern  double cv[64];
extern  double rhoq[64];
extern double ru1;
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (k = 1; k <= grid_points[2] - 2; k++) {
        int j_start = 0, j_end = grid_points[1] - 1;
        if (grid_points[1] < 4) continue;
        for (j = j_start; j <= j_end; j++) {
            ru1 = c3c4 * rho_i[i][j][k];
            cv[j] = vs[i][j][k];
            double base_val = dymax + ru1;
            if (base_val > dy1) {
                double val1 = dy5 + c1c5 * ru1;
                double val2 = dy3 + con43 * ru1;
                if (val1 > base_val) {
                    if (val2 > val1) {
                        rhoq[j] = val2;
                    } else {
                        rhoq[j] = val1;
                    }
                } else {
                    if (val2 > base_val) {
                        rhoq[j] = val2;
                    } else {
                        rhoq[j] = base_val;
                    }
                }
            } else {
                rhoq[j] = dy3 + con43 * ru1;
            }
        }
        for (j = 1; j <= grid_points[1] - 2; j++) {
            lhs[0][i][j][k] = 0.;
            lhs[1][i][j][k] = -dtty2 * cv[j - 1] - dtty1 * rhoq[j - 1];
            lhs[2][i][j][k] = 1. + c2dtty1 * rhoq[j];
            lhs[3][i][j][k] = dtty2 * cv[j + 1] - dtty1 * rhoq[j + 1];
            lhs[4][i][j][k] = 0.;
        }
    }
}
}
