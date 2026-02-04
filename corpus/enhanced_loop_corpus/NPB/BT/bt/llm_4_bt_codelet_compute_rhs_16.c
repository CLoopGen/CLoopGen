#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern  double rhs[65][65][65][5];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j++) {
            for (k = 0; k < grid_points[2]; k++) {
                if (!((i + j + k) % 2)) {
                    for (m = 0; m < 5; m++) {
                        rhs[i][j][k][m] = forcing[i][j][k][m];
                    }
                }
            }
        }
    }
}
