#include <stdio.h>

extern  int grid_points[3];
extern  double dtty2;
extern  double speed[65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 1; k <= grid_points[2] - 2; k++) {
            double base_val_0 = lhs[0][i][j][k];
            double base_val_1 = lhs[1][i][j][k];
            double base_val_2 = lhs[2][i][j][k];
            double base_val_3 = lhs[3][i][j][k];
            double base_val_4 = lhs[4][i][j][k];
            double s1 = dtty2 * speed[i][j - 1][k];
            double s2 = dtty2 * speed[i][j + 1][k];
            lhs[5][i][j][k] = base_val_0;
            lhs[6][i][j][k] = base_val_1 - s1;
            lhs[7][i][j][k] = base_val_2;
            lhs[8][i][j][k] = base_val_3 + s2;
            lhs[9][i][j][k] = base_val_4;
            lhs[10][i][j][k] = base_val_0;
            lhs[11][i][j][k] = base_val_1 + s1;
            lhs[12][i][j][k] = base_val_2;
            lhs[13][i][j][k] = base_val_3 - s2;
            lhs[14][i][j][k] = base_val_4;
        }
    }
}
}
