#include <stdio.h>

extern  int grid_points[3];
extern  double comz1;
extern  double comz4;
extern  double comz6;
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;



void loop(){
    for (i = 3; i <= grid_points[0] - 4; i++) {
        double local_comz1 = comz1 * 1.0;
        double local_comz4 = comz4 * 1.0;
        double local_comz6 = comz6 * 1.0;
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                lhs[0][i][j][k] = lhs[0][i][j][k] + local_comz1;
                lhs[1][i][j][k] = lhs[4][i][j][k] - local_comz4; // RAW dependency: uses updated lhs[4]
                lhs[2][i][j][k] = lhs[2][i][j][k] + local_comz6;
                lhs[3][i][j][k] = lhs[1][i][j][k] - local_comz4; // WAW & WAR: depends on prior write to lhs[1], overwrites lhs[3]
                lhs[4][i][j][k] = lhs[4][i][j][k] + local_comz1;
            }
        }
    }
}
