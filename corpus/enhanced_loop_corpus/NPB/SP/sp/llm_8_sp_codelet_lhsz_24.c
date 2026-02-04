#include <stdio.h>

extern  int grid_points[3];
extern  double dttz2;
extern  double speed[65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k += 2) {
            double speed_km1 = speed[i][j][k - 1];
            double speed_kp1 = speed[i][j][k + 1];
            double temp1 = dttz2 * speed_km1;
            double temp2 = dttz2 * speed_kp1;

            lhs[5][i][j][k] = lhs[0][i][j][k];
            lhs[6][i][j][k] = lhs[1][i][j][k] - temp1;
            lhs[7][i][j][k] = lhs[2][i][j][k];
            lhs[8][i][j][k] = lhs[3][i][j][k] + temp2;
            lhs[9][i][j][k] = lhs[4][i][j][k];

            lhs[10][i][j][k] = lhs[0][i][j][k];
            lhs[11][i][j][k] = lhs[1][i][j][k] + temp1;
            lhs[12][i][j][k] = lhs[2][i][j][k];
            lhs[13][i][j][k] = lhs[3][i][j][k] - temp2;
            lhs[14][i][j][k] = lhs[4][i][j][k];

            if (k + 1 <= grid_points[2] - 2) {
                double speed_km1_next = speed[i][j][k];
                double speed_kp1_next = speed[i][j][k + 2];
                double temp1_next = dttz2 * speed_km1_next;
                double temp2_next = dttz2 * speed_kp1_next;

                lhs[5][i][j][k+1] = lhs[0][i][j][k+1];
                lhs[6][i][j][k+1] = lhs[1][i][j][k+1] - temp1_next;
                lhs[7][i][j][k+1] = lhs[2][i][j][k+1];
                lhs[8][i][j][k+1] = lhs[3][i][j][k+1] + temp2_next;
                lhs[9][i][j][k+1] = lhs[4][i][j][k+1];

                lhs[10][i][j][k+1] = lhs[0][i][j][k+1];
                lhs[11][i][j][k+1] = lhs[1][i][j][k+1] + temp1_next;
                lhs[12][i][j][k+1] = lhs[2][i][j][k+1];
                lhs[13][i][j][k+1] = lhs[3][i][j][k+1] - temp2_next;
                lhs[14][i][j][k+1] = lhs[4][i][j][k+1];
            }
        }
    }
}
}
