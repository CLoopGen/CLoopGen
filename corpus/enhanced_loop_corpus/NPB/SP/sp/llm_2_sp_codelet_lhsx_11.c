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
for (j = 1; j <= grid_points[1] - 2; j++) {
    for (k = 1; k <= grid_points[2] - 2; k++) {
        // Change memory access pattern by reordering and grouping accesses to improve spatial locality
        double temp_comz5 = comz5;
        double temp_comz4 = comz4;
        double temp_comz1 = comz1;
        double temp_comz6 = comz6;

        lhs[2][i][j][k] += temp_comz5;
        lhs[3][i][j][k] -= temp_comz4;
        lhs[4][i][j][k] += temp_comz1;

        lhs[1][i + 1][j][k] -= temp_comz4;
        lhs[2][i + 1][j][k] += temp_comz6;
        lhs[3][i + 1][j][k] -= temp_comz4;
        lhs[4][i + 1][j][k] += temp_comz1;
    }
}
}
