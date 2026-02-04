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
            int base_k = k;
            lhs[5][i][j][base_k] = lhs[0][i][j][base_k];
            lhs[6][i][j][base_k] = lhs[1][i][j][base_k] - dtty2 * speed[i][j - 1][base_k];
            lhs[7][i][j][base_k] = lhs[2][i][j][base_k];
            lhs[8][i][j][base_k] = lhs[3][i][j][base_k] + dtty2 * speed[i][j + 1][base_k];
            lhs[9][i][j][base_k] = lhs[4][i][j][base_k];
            lhs[10][i][j][base_k] = lhs[0][i][j][base_k];
            lhs[11][i][j][base_k] = lhs[1][i][j][base_k] + dtty2 * speed[i][j - 1][base_k];
            lhs[12][i][j][base_k] = lhs[2][i][j][base_k];
            lhs[13][i][j][base_k] = lhs[3][i][j][base_k] - dtty2 * speed[i][j + 1][base_k];
            lhs[14][i][j][base_k] = lhs[4][i][j][base_k];
        }
    }
}
}
