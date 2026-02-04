#include <stdio.h>

extern  int grid_points[3];
extern  double forcing[65][65][65][6];
extern int m;
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        for (k = 1; k < grid_points[2] - 1; k++) {
            forcing[i][j][k][0] = -1. * forcing[i][j][k][0];
            forcing[i][j][k][1] = -1. * forcing[i][j][k][1];
            forcing[i][j][k][2] = -1. * forcing[i][j][k][2];
            forcing[i][j][k][3] = -1. * forcing[i][j][k][3];
            forcing[i][j][k][4] = -1. * forcing[i][j][k][4];
        }
    }
}
}
