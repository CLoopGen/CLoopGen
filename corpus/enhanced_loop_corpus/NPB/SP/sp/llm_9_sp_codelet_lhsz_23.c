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
// Reduce computational load and modify trip count for lower intensity
for (i = 2; i <= grid_points[0] - 3; i += 2) {
    for (j = 2; j <= grid_points[1] - 3; j += 2) {
        double temp1 = comz1 - comz4;
        double temp2 = comz5 + comz6;

        lhs[0][i][j][k] += temp1;
        lhs[2][i][j][k] += temp2;
        lhs[0][i][j][k + 1] += temp1;
        lhs[2][i][j][k + 1] += comz5;
    }
}
}
