#include <stdio.h>

extern  int grid_points[3];
extern  double u[5][65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (m = 0; m < 5; m++) {
    for (i = 1; i <= grid_points[0] - 2; i += 2) {
        for (j = 1; j <= grid_points[1] - 2; j += 2) {
            for (k = 1; k <= grid_points[2] - 2; k += 2) {
                u[m][i][j][k] = u[m][i][j][k] + rhs[m][i][j][k];
            }
        }
    }
}
}
