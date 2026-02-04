#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern double rms[5];
extern int i;
extern int j;
extern int k;
extern int m;
extern double add;



void loop(){
    for (m = 0; m < 5; m++) {
        double local_sum = 0.0;
        for (i = 0; i <= grid_points[0] - 2; i++) {
            for (j = 0; j <= grid_points[1] - 2; j++) {
                for (k = 0; k <= grid_points[2] - 2; k++) {
                    add = rhs[m][i][j][k];
                    local_sum = local_sum + add * add;
                }
            }
        }
        rms[m] = local_sum;
    }
}
