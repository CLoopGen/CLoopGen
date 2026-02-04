#include <stdio.h>

extern  int grid_points[3];
extern  double dx1;
extern  double dx2;
extern  double dx5;
extern  double dxmax;
extern  double c1c5;
extern  double c3c4;
extern  double dttx1;
extern  double dttx2;
extern  double c2dttx1;
extern  double con43;
extern  double us[65][65][65];
extern  double rho_i[65][65][65];
extern  double lhs[15][65][65][65];
extern  double cv[64];
extern  double rhon[64];
extern double ru1;
extern int i;
extern int j;
extern int k;



void loop(){
for (j = 1; j <= grid_points[1] - 2; j++) {
    for (k = 1; k <= grid_points[2] - 2; k++) {
        double prev_cv, prev_rhon, curr_cv, curr_rhon, next_cv, next_rhon;
        for (i = 0; i <= grid_points[0] - 1; i++) {
            ru1 = c3c4 * rho_i[i][j][k];
            cv[i] = us[i][j][k];
            rhon[i] = (((dx2 + con43 * ru1) > ((((dx5 + c1c5 * ru1) > ((((dxmax + ru1) > (dx1)) ? (dxmax + ru1) : (dx1)))) ? (dx5 + c1c5 * ru1) : ((((dxmax + ru1) > (dx1)) ? (dxmax + ru1) : (dx1)))))) ? (dx2 + con43 * ru1) : ((((dx5 + c1c5 * ru1) > ((((dxmax + ru1) > (dx1)) ? (dxmax + ru1) : (dx1)))) ? (dx5 + c1c5 * ru1) : ((((dxmax + ru1) > (dx1)) ? (dxmax + ru1) : (dx1))))));
        }
        prev_cv = cv[0]; prev_rhon = rhon[0];
        curr_cv = cv[1]; curr_rhon = rhon[1];
        for (i = 1; i <= grid_points[0] - 2; i++) {
            if (i + 1 < grid_points[0]) {
                next_cv = cv[i + 1];
                next_rhon = rhon[i + 1];
            } else {
                next_cv = curr_cv; 
                next_rhon = curr_rhon;
            }
            lhs[0][i][j][k] = 0.;
            lhs[1][i][j][k] = -dttx2 * prev_cv - dttx1 * prev_rhon;
            lhs[2][i][j][k] = 1. + c2dttx1 * curr_rhon;
            lhs[3][i][j][k] = dttx2 * next_cv - dttx1 * next_rhon;
            lhs[4][i][j][k] = 0.;
            prev_cv = curr_cv;
            prev_rhon = curr_rhon;
            curr_cv = next_cv;
            curr_rhon = next_rhon;
        }
    }
}
}
