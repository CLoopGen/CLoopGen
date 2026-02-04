#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;



void loop(){
    for (n = 0; n < 3; n++) {
        for (i = 1; i < grid_points[0]; i++) {
            for (j = 1; j < grid_points[1]; j++) {
                for (k = 1; k < grid_points[2]; k++) {
                    lhs[5 * n + 2][i][j][k] = lhs[5 * n + 2][i-1][j-1][k-1] + 1.0;
                }
            }
        }
    }
}
