#include <stdio.h>

extern  int grid_points[3];
extern  double comz1;
extern  double comz4;
extern  double comz5;
extern  double comz6;
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
// Reduced computational intensity and modified trip count for lower complexity
int step = 2;
for (i = 1; i <= grid_points[0] - 2; i += step) {
    for (j = 1; j <= grid_points[1] - 2; j += step) {
        lhs[2][i][j][k] += comz5;
        lhs[3][i][j][k] -= comz4;
        lhs[4][i][j][k] += comz1;
        if (k + 1 < 65) {
            lhs[2][i][j][k + 1] += comz6;
            lhs[4][i][j][k + 1] += comz1;
        }
    }
}
}
