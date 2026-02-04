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
for (i = 1; i <= grid_points[0] - 2; i += 2) {
    for (k = 1; k <= grid_points[2] - 2; k += 2) {
        for (j = 0; j <= grid_points[1] - 1; j++) {
            ru1 = c3c4 * rho_i[i][j][k];
            cv[j] = vs[i][j][k];
            double base_val = dymax + ru1;
            double dy1_val = dy1;
            double val1 = base_val > dy1_val ? base_val : dy1_val;
            double val2 = dy5 + c1c5 * ru1;
            double val3 = val2 > val1 ? val2 : val1;
            double val4 = dy3 + con43 * ru1;
            rhoq[j] = val4 > val3 ? val4 : val3;
        }
        for (j = 2; j <= grid_points[1] - 3; j += 2) {
            lhs[0][i][j][k] = 0.0;
            lhs[1][i][j][k] = -dtty2 * cv[j - 1] - dtty1 * rhoq[j - 1];
            lhs[2][i][j][k] = 1.0 + c2dtty1 * rhoq[j];
            lhs[3][i][j][k] = dtty2 * cv[j + 1] - dtty1 * rhoq[j + 1];
            lhs[4][i][j][k] = 0.0;

            if (i+1 <= grid_points[0]-2 && k+1 <= grid_points[2]-2 && j+1 <= grid_points[1]-3) {
                int i1 = i+1, k1 = k+1, j1 = j+1;
                lhs[0][i1][j1][k1] = 0.0;
                lhs[1][i1][j1][k1] = -dtty2 * cv[j1 - 1] - dtty1 * rhoq[j1 - 1];
                lhs[2][i1][j1][k1] = 1.0 + c2dtty1 * rhoq[j1];
                lhs[3][i1][j1][k1] = dtty2 * cv[j1 + 1] - dtty1 * rhoq[j1 + 1];
                lhs[4][i1][j1][k1] = 0.0;
            }
        }
    }
}
}
