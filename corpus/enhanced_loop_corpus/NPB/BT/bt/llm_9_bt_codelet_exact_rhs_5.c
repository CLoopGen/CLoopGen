#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
    for (i = 2; i < grid_points[0] - 2; i += 2) {
        for (j = 2; j < grid_points[1] - 2; j += 2) {
            for (k = 2; k < grid_points[2] - 2; k += 2) {
                double sum = 0.0;
                for (m = 0; m < 5; m++) {
                    sum += forcing[i][j][k][m] + forcing[i-1][j][k][m] + forcing[i+1][j][k][m];
                    forcing[i][j][k][m] = -0.5 * forcing[i][j][k][m];
                }
                forcing[i][j][k][5] = sum / 15.0;
            }
        }
    }
}
