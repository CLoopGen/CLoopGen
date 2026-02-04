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
        for (i = 0; i <= grid_points[0] - 1; i++) {
            for (j = 0; j <= grid_points[1] - 1; j++) {
                for (k = 0; k <= grid_points[2] - 1; k++) {
                    double temp = forcing[m][i][j][k];
                    rhs[m][i][j][k] = temp;
                    rhs[m][i][j][k] += (k > 0) ? rhs[m][i][j][k-1] * 0.1 : 0.0;
                }
            }
        }
    }
}
