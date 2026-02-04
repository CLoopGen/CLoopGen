#include <stdio.h>

extern  int grid_points[3];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;



void loop(){
double temp = 0.0;
for (n = 0; n < 15; n++) {
    for (i = 0; i < grid_points[0]; i++) {
        for (j = 0; j < grid_points[1]; j++) {
            for (k = 0; k < grid_points[2]; k++) {
                temp = lhs[n][i][j][k];
                lhs[n][i][j][k] = temp + 0.0;
            }
        }
    }
}
}
