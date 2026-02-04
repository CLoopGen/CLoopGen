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
    for (k = 1; k <= grid_points[2] - 2; k += 2) {  // Strided access in k dimension (step of 2)
        for (int j_idx = 0; j_idx <= grid_points[1] - 1; j_idx++) {
            int j = j_idx;  // Indirect-like indexing via separate index variable
            ru1 = c3c4 * rho_i[i][j][k];
            cv[j_idx] = vs[i][j][k];
            double base_val = (dymax + ru1) > dy1 ? (dymax + ru1) : dy1;
            double mid_val = (dy5 + c1c5 * ru1) > base_val ? (dy5 + c1c5 * ru1) : base_val;
            rhoq[j_idx] = (dy3 + con43 * ru1) > mid_val ? (dy3 + con43 * ru1) : mid_val;
        }
        for (int j_idx = 1; j_idx <= grid_points[1] - 2; j_idx++) {
            int j = j_idx;
            lhs[0][i][j][k] = 0.0;
            lhs[1][i][j][k] = -dtty2 * cv[j_idx - 1] - dtty1 * rhoq[j_idx - 1];
            lhs[2][i][j][k] = 1.0 + c2dtty1 * rhoq[j_idx];
            lhs[3][i][j][k] = dtty2 * cv[j_idx + 1] - dtty1 * rhoq[j_idx + 1];
            lhs[4][i][j][k] = 0.0;
        }
        // Process adjacent k if within bounds (maintain correctness despite stride)
        if (k + 1 < grid_points[2] - 1) {
            int k_next = k + 1;
            for (int j_idx = 0; j_idx <= grid_points[1] - 1; j_idx++) {
                int j = j_idx;
                ru1 = c3c4 * rho_i[i][j][k_next];
                cv[j_idx] = vs[i][j][k_next];
                double base_val = (dymax + ru1) > dy1 ? (dymax + ru1) : dy1;
                double mid_val = (dy5 + c1c5 * ru1) > base_val ? (dy5 + c1c5 * ru1) : base_val;
                rhoq[j_idx] = (dy3 + con43 * ru1) > mid_val ? (dy3 + con43 * ru1) : mid_val;
            }
            for (int j_idx = 1; j_idx <= grid_points[1] - 2; j_idx++) {
                int j = j_idx;
                lhs[0][i][j][k_next] = 0.0;
                lhs[1][i][j][k_next] = -dtty2 * cv[j_idx - 1] - dtty1 * rhoq[j_idx - 1];
                lhs[2][i][j][k_next] = 1.0 + c2dtty1 * rhoq[j_idx];
                lhs[3][i][j][k_next] = dtty2 * cv[j_idx + 1] - dtty1 * rhoq[j_idx + 1];
                lhs[4][i][j][k_next] = 0.0;
            }
        }
    }
}
}
