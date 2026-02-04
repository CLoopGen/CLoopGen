#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;



void loop(){
for (n = 0; n < 3; n += 2) {
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j += 2) {
            for (k = 0; k < grid_points[2]; k++) {
                lhs[5 * n + 2][i][j][k] = 1.;
                if (j+1 < grid_points[1]) {
                    lhs[5 * n + 2][i][j+1][k] = 1.;
                }
            }
        }
    }
}
}
