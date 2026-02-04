#include <stdio.h>

extern  int grid_points[3];
extern  double dz1;
extern  double dz4;
extern  double dz5;
extern  double dzmax;
extern  double c1c5;
extern  double c3c4;
extern  double dttz1;
extern  double dttz2;
extern  double c2dttz1;
extern  double con43;
extern  double ws[65][65][65];
extern  double rho_i[65][65][65];
extern  double lhs[15][65][65][65];
extern  double cv[64];
extern  double rhos[64];
extern double ru1;
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        int base_idx = i * 65 * 65 + j * 65;
        for (k = 0; k <= grid_points[2] - 1; k++) {
            ru1 = c3c4 * rho_i[i][j][k];
            cv[k] = ws[i][j][k];
            rhos[k] = (((dz4 + con43 * ru1) > ((((dz5 + c1c5 * ru1) > ((((dzmax + ru1) > (dz1)) ? (dzmax + ru1) : (dz1)))) ? (dz5 + c1c5 * ru1) : ((((dzmax + ru1) > (dz1)) ? (dzmax + ru1) : (dz1)))))) ? (dz4 + con43 * ru1) : ((((dz5 + c1c5 * ru1) > ((((dzmax + ru1) > (dz1)) ? (dzmax + ru1) : (dz1)))) ? (dz5 + c1c5 * ru1) : ((((dzmax + ru1) > (dz1)) ? (dzmax + ru1) : (dz1))))));
        }
        for (k = 1; k <= grid_points[2] - 2; k++) {
            lhs[0][i][j][k] = 0.;
            lhs[1][i][j][k] = -dttz2 * cv[k - 1] - dttz1 * rhos[k - 1];
            lhs[2][i][j][k] = 1. + c2dttz1 * rhos[k];
            lhs[3][i][j][k] = dttz2 * cv[k + 1] - dttz1 * rhos[k + 1];
            lhs[4][i][j][k] = 0.;
        }
    }
}
}
