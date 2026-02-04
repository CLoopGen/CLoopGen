#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[5][65][65][65];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
for (m = 0; m < 5; m++) {
    for (i = 1; i <= grid_points[0] - 2; i++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k += 2) {
                forcing[m][i][j][k] = -1. * forcing[m][i][j][k];
                if (k + 1 <= grid_points[2] - 2) {
                    forcing[m][i][j][k + 1] = -1. * forcing[m][i][j][k + 1];
                }
            }
        }
    }
}
}
