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
            k = 0;
            while (k <= grid_points[2] - 1) {
                rhs[m][i][j][k] = forcing[m][i][j][k];
                k++;
            }
        }
    }
}
}
