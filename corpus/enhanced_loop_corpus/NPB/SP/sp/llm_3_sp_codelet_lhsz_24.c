#include <stdio.h>

extern  int grid_points[3];
extern  double dttz2;
extern  double speed[65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
    for (k = 1; k <= grid_points[2] - 2; k++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (i = 1; i <= grid_points[0] - 2; i++) {
                double* lhs_base = &lhs[0][i][j][k];
                double speed_km1 = speed[i][j][k - 1];
                double speed_kp1 = speed[i][j][k + 1];

                lhs_base[5] = lhs_base[0];
                lhs_base[6] = lhs_base[1] - dttz2 * speed_km1;
                lhs_base[7] = lhs_base[2];
                lhs_base[8] = lhs_base[3] + dttz2 * speed_kp1;
                lhs_base[9] = lhs_base[4];

                lhs_base[10] = lhs_base[0];
                lhs_base[11] = lhs_base[1] + dttz2 * speed_km1;
                lhs_base[12] = lhs_base[2];
                lhs_base[13] = lhs_base[3] - dttz2 * speed_kp1;
                lhs_base[14] = lhs_base[4];
            }
        }
    }
}
