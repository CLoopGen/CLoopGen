#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[65][65][65][3][5][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (i = 0; i < grid_points[0]; i += 2) {
        for (j = 0; j < grid_points[1]; j += 2) {
            for (k = 0; k < grid_points[2]; k += 2) {
                for (m = 0; m < 5; m++) {
                    lhs[i][j][k][1][m][m] = 1.0;
                    if (i + 1 < grid_points[0]) {
                        lhs[i+1][j][k][1][m][m] = 1.0;
                    }
                    if (j + 1 < grid_points[1]) {
                        lhs[i][j+1][k][1][m][m] = 1.0;
                    }
                    if (k + 1 < grid_points[2]) {
                        lhs[i][j][k+1][1][m][m] = 1.0;
                    }
                }
            }
        }
    }
}
