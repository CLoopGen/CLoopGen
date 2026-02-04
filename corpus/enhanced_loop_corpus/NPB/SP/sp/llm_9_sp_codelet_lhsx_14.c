#include <stdio.h>

extern  int grid_points[3];
extern  double dttx2;
extern  double speed[65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 2; i <= grid_points[0] - 3; i++) {
    for (j = 2; j <= grid_points[1] - 3; j++) {
        for (k = 2; k <= grid_points[2] - 3; k++) {
            double s1 = speed[i-1][j][k];
            double s2 = speed[i+1][j][k];
            double s3 = speed[i][j-1][k];
            double s4 = speed[i][j+1][k];
            double s5 = speed[i][j][k-1];
            double s6 = speed[i][j][k+1];
            double factor = dttx2 * 0.2;

            lhs[5][i][j][k] = lhs[0][i][j][k];
            lhs[6][i][j][k] = lhs[1][i][j][k] - dttx2 * s1 + factor * (s3 + s5);
            lhs[7][i][j][k] = lhs[2][i][j][k] + factor * (s1 + s2 - s3 - s4);
            lhs[8][i][j][k] = lhs[3][i][j][k] + dttx2 * s2 - factor * (s4 + s6);
            lhs[9][i][j][k] = lhs[4][i][j][k] + factor * (s2 + s4 + s6);

            lhs[10][i][j][k] = lhs[0][i][j][k];
            lhs[11][i][j][k] = lhs[1][i][j][k] + dttx2 * s1 - factor * (s3 + s5);
            lhs[12][i][j][k] = lhs[2][i][j][k] + factor * (s1 + s2 - s3 - s4);
            lhs[13][i][j][k] = lhs[3][i][j][k] - dttx2 * s2 + factor * (s4 + s6);
            lhs[14][i][j][k] = lhs[4][i][j][k] + factor * (s1 + s3 + s5);
        }
    }
}
}
