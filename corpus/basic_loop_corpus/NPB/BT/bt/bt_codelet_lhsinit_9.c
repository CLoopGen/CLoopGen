#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[65][65][65][3][5][5];
extern int i;
extern int j;
extern int k;
extern int m;

void loop(){
for (i = 0; i < grid_points[0]; i++) {
    for (j = 0; j < grid_points[1]; j++) {
        for (k = 0; k < grid_points[2]; k++) {
            for (m = 0; m < 5; m++) {
                lhs[i][j][k][1][m][m] = 1.;
            }
        }
    }
}

}
