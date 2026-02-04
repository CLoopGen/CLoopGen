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
        lhs[5][i][j][1] = lhs[0][i][j][1];
        lhs[6][i][j][1] = lhs[1][i][j][1] - dtty2 * speed[i][j - 1][1];
        lhs[7][i][j][1] = lhs[2][i][j][1];
        lhs[8][i][j][1] = lhs[3][i][j][1] + dtty2 * speed[i][j + 1][1];
        lhs[9][i][j][1] = lhs[4][i][j][1];
        lhs[10][i][j][1] = lhs[0][i][j][1];
        lhs[11][i][j][1] = lhs[1][i][j][1] + dtty2 * speed[i][j - 1][1];
        lhs[12][i][j][1] = lhs[2][i][j][1];
        lhs[13][i][j][1] = lhs[3][i][j][1] - dtty2 * speed[i][j + 1][1];
        lhs[14][i][j][1] = lhs[4][i][j][1];
        for (k = 2; k <= grid_points[2] - 2; k++) {
            lhs[5][i][j][k] = lhs[0][i][j][k];
            lhs[6][i][j][k] = lhs[1][i][j][k] - dtty2 * speed[i][j - 1][k];
            lhs[7][i][j][k] = lhs[2][i][j][k];
            lhs[8][i][j][k] = lhs[3][i][j][k] + dtty2 * speed[i][j + 1][k];
            lhs[9][i][j][k] = lhs[4][i][j][k];
            lhs[10][i][j][k] = lhs[0][i][j][k];
            lhs[11][i][j][k] = lhs[1][i][j][k] + dtty2 * speed[i][j - 1][k];
            lhs[12][i][j][k] = lhs[2][i][j][k];
            lhs[13][i][j][k] = lhs[3][i][j][k] - dtty2 * speed[i][j + 1][k];
            lhs[14][i][j][k] = lhs[4][i][j][k];
        }
    }
}
}
