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
for (i = 2; i <= grid_points[0] - 4; i += 2) {
    for (k = 1; k <= grid_points[2] - 2; k++) {
        double temp1 = comz1 + comz5;
        double temp2 = comz4 * 2.0;
        double temp3 = comz6 - comz1;
        lhs[0][i][j][k] += temp1;
        lhs[1][i][j][k] -= temp2;
        lhs[2][i][j][k] += temp3;
        lhs[3][i][j][k] -= temp2;
        lhs[0][i][j + 1][k] += temp1;
        lhs[1][i][j + 1][k] -= temp2;
        lhs[2][i][j + 1][k] += comz5;
        if (i > 2) {
            lhs[0][i-1][j][k] += comz1;
            lhs[2][i-1][j][k] += comz6;
        }
    }
}
}
