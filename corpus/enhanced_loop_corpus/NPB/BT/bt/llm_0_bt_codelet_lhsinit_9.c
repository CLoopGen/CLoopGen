#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[65][65][65][3][5][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j++) {
            for (k = 0; k < grid_points[2]; k++) {
                lhs[i][j][k][1][0][0] = 1.;
                lhs[i][j][k][1][1][1] = 1.;
                lhs[i][j][k][1][2][2] = 1.;
                lhs[i][j][k][1][3][3] = 1.;
                lhs[i][j][k][1][4][4] = 1.;
            }
        }
    }
}
