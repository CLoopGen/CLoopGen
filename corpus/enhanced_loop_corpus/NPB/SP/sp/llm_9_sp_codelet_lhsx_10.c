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
for (j = 1; j <= grid_points[1] - 2; j += 2) {
    for (k = 1; k <= grid_points[2] - 2; k += 2) {
        if (j + 1 >= grid_points[1] - 2 || k + 1 >= grid_points[2] - 2) continue;
        for (i = 0; i <= grid_points[0] - 1; i++) {
            ru1 = c3c4 * rho_i[i][j][k];
            cv[i] = us[i][j][k];
            double temp_max = dx1;
            if (dxmax + ru1 > temp_max) temp_max = dxmax + ru1;
            if (dx5 + c1c5 * ru1 > temp_max) temp_max = dx5 + c1c5 * ru1;
            if (dx2 + con43 * ru1 > temp_max) temp_max = dx2 + con43 * ru1;
            rhon[i] = temp_max;
        }
        for (i = 1; i <= grid_points[0] - 2; i++) {
            lhs[0][i][j][k] = 0.0;
            lhs[1][i][j][k] = -dttx2 * cv[i - 1] - dttx1 * rhon[i - 1];
            lhs[2][i][j][k] = 1.0 + c2dttx1 * rhon[i];
            lhs[3][i][j][k] = dttx2 * cv[i + 1] - dttx1 * rhon[i + 1];
            lhs[4][i][j][k] = 0.0;

            lhs[0][i][j+1][k] = 0.0;
            lhs[1][i][j+1][k] = -dttx2 * cv[i - 1] - dttx1 * rhon[i - 1];
            lhs[2][i][j+1][k] = 1.0 + c2dttx1 * rhon[i];
            lhs[3][i][j+1][k] = dttx2 * cv[i + 1] - dttx1 * rhon[i + 1];
            lhs[4][i][j+1][k] = 0.0;

            lhs[0][i][j][k+1] = 0.0;
            lhs[1][i][j][k+1] = -dttx2 * cv[i - 1] - dttx1 * rhon[i - 1];
            lhs[2][i][j][k+1] = 1.0 + c2dttx1 * rhon[i];
            lhs[3][i][j][k+1] = dttx2 * cv[i + 1] - dttx1 * rhon[i + 1];
            lhs[4][i][j][k+1] = 0.0;

            lhs[0][i][j+1][k+1] = 0.0;
            lhs[1][i][j+1][k+1] = -dttx2 * cv[i - 1] - dttx1 * rhon[i - 1];
            lhs[2][i][j+1][k+1] = 1.0 + c2dttx1 * rhon[i];
            lhs[3][i][j+1][k+1] = dttx2 * cv[i + 1] - dttx1 * rhon[i + 1];
            lhs[4][i][j+1][k+1] = 0.0;
        }
    }
}
}
