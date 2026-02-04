#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;



void loop(){
for (n = 0; n < 15; n += 3) {
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j++) {
            for (k = 0; k < grid_points[2]; k += 2) {
                lhs[n][i][j][k] = 0.;
                if (n+1 < 15) lhs[n+1][i][j][k] = 0.;
                if (n+2 < 15) lhs[n+2][i][j][k] = 0.;
                if (k+1 < grid_points[2]) lhs[n][i][j][k+1] = 0.;
            }
        }
    }
}
}
