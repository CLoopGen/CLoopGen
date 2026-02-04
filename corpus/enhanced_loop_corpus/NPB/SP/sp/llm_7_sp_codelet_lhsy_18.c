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
        double prev_val = 0.0;
        for (k = 1; k <= grid_points[2] - 2; k++) {
            // Introduce a loop-carried dependency via 'prev_val' (WAW and RAW)
            double current_val = lhs[0][i][j][k] + comz1 + prev_val;
            lhs[0][i][j][k] = current_val;
            lhs[1][i][j][k] = lhs[1][i][j][k] - comz4;
            lhs[2][i][j][k] = lhs[2][i][j][k] + comz6;
            lhs[3][i][j][k] = lhs[3][i][j][k] - comz4;

            lhs[0][i][j + 1][k] = lhs[0][i][j + 1][k] + comz1;
            lhs[1][i][j + 1][k] = lhs[1][i][j + 1][k] - comz4;
            lhs[2][i][j + 1][k] = lhs[2][i][j + 1][k] + comz5;

            prev_val = current_val; // Loop-carried dependency: current iteration depends on previous k
        }
    }
}
