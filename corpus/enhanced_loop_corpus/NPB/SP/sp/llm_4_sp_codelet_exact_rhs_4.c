#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[5][65][65][65];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
    for (m = 0; m < 5; m++) {
        for (i = 0; i <= grid_points[0] - 1; i++) {
            for (j = 0; j <= grid_points[1] - 1; j++) {
                if (i % 2 == 0) {
                    for (k = 0; k <= grid_points[2] - 1; k++) {
                        forcing[m][i][j][k] = 0.;
                    }
                } else {
                    for (k = grid_points[2] - 1; k >= 0; k--) {
                        forcing[m][i][j][k] = 0.;
                    }
                }
            }
        }
    }
}
