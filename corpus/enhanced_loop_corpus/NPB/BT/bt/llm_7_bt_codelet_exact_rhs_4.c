#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j++) {
            for (k = 0; k < grid_points[2]; k++) {
                for (m = 4; m >= 0; m--) {
                    forcing[i][j][k][m] = 0.;
                    if (m > 0) {
                        forcing[i][j][k][m-1] = forcing[i][j][k][m] + 1.0;
                    }
                }
            }
        }
    }
}
