#include <stdio.h>

extern  int grid_points[3];
extern  double comz1;
extern  double comz4;
extern  double comz5;
extern  double comz6;
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (int kk = k; kk <= k + 1; kk++) {
            lhs[0][i][j][kk] = lhs[0][i][j][kk] + comz1;
            lhs[1][i][j][kk] = lhs[1][i][j][kk] - comz4;
            if (kk == k) {
                lhs[2][i][j][kk] = lhs[2][i][j][kk] + comz6;
                lhs[3][i][j][kk] = lhs[3][i][j][kk] - comz4;
            } else {
                lhs[2][i][j][kk] = lhs[2][i][j][kk] + comz5;
            }
        }
    }
}
}
