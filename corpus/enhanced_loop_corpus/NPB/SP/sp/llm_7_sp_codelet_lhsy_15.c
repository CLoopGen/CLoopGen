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
        double prev_cv, prev_rhoq;
        double current_cv, current_rhoq;
        ru1 = c3c4 * rho_i[i][0][k];
        current_cv = vs[i][0][k];
        double base1 = dymax + ru1;
        double base2 = dy1;
        double mid_max = (base1 > base2) ? base1 : base2;
        double high_mid = (dy5 + c1c5 * ru1) > mid_max ? (dy5 + c1c5 * ru1) : mid_max;
        current_rhoq = (dy3 + con43 * ru1) > high_mid ? (dy3 + con43 * ru1) : high_mid;
        cv[0] = current_cv;
        rhoq[0] = current_rhoq;
        prev_cv = current_cv;
        prev_rhoq = current_rhoq;

        for (j = 1; j <= grid_points[1] - 2; j++) {
            ru1 = c3c4 * rho_i[i][j][k];
            current_cv = vs[i][j][k];
            base1 = dymax + ru1;
            mid_max = (base1 > base2) ? base1 : base2;
            high_mid = (dy5 + c1c5 * ru1) > mid_max ? (dy5 + c1c5 * ru1) : mid_max;
            current_rhoq = (dy3 + con43 * ru1) > high_mid ? (dy3 + con43 * ru1) : high_mid;

            lhs[0][i][j][k] = 0.0;
            lhs[1][i][j][k] = -dtty2 * prev_cv - dtty1 * prev_rhoq;
            lhs[2][i][j][k] = 1.0 + c2dtty1 * current_rhoq;
            lhs[3][i][j][k] = dtty2 * current_cv - dtty1 * current_rhoq; 
            lhs[4][i][j][k] = 0.0;

            cv[j] = current_cv;
            rhoq[j] = current_rhoq;
            prev_cv = current_cv;
            prev_rhoq = current_rhoq;
        }
        j = grid_points[1] - 1;
        if (j >= 1) {
            ru1 = c3c4 * rho_i[i][j][k];
            double tmp_max = (dymax + ru1) > dy1 ? (dymax + ru1) : dy1;
            tmp_max = (dy5 + c1c5 * ru1) > tmp_max ? (dy5 + c1c5 * ru1) : tmp_max;
            rhoq[j] = (dy3 + con43 * ru1) > tmp_max ? (dy3 + con43 * ru1) : tmp_max;
            cv[j] = vs[i][j][k];
        }
    }
}
}
