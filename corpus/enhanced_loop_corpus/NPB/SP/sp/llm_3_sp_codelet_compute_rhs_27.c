#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double forcing[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
for (m = 0; m < 5; m++) {
    for (i = 0; i <= grid_points[0] - 1; i += 2) {
        for (j = 0; j <= grid_points[1] - 1; j += 2) {
            for (k = 0; k <= grid_points[2] - 1; k += 2) {
                rhs[m][i][j][k] = forcing[m][i][j][k];
                if (i + 1 < grid_points[0]) {
                    rhs[m][i+1][j][k] = forcing[m][i+1][j][k];
                }
                if (j + 1 < grid_points[1]) {
                    rhs[m][i][j+1][k] = forcing[m][i][j+1][k];
                }
                if (k + 1 < grid_points[2]) {
                    rhs[m][i][j][k+1] = forcing[m][i][j][k+1];
                }
            }
        }
    }
}
}
