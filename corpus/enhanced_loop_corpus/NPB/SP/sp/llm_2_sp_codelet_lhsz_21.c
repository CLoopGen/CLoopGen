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
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        // Change memory access pattern by reordering and grouping accesses to improve spatial locality
        double *lhs_2_jk = lhs[2][i][j];
        double *lhs_3_jk = lhs[3][i][j];
        double *lhs_4_jk = lhs[4][i][j];
        double *lhs_1_next_jk = lhs[1][i][j] + 1;
        double *lhs_2_next_jk = lhs[2][i][j] + 1;
        double *lhs_3_next_jk = lhs[3][i][j] + 1;
        double *lhs_4_next_jk = lhs[4][i][j] + 1;

        lhs_2_jk[k] += comz5;
        lhs_3_jk[k] -= comz4;
        lhs_4_jk[k] += comz1;
        lhs_1_next_jk[k] -= comz4;
        lhs_2_next_jk[k] += comz6;
        lhs_3_next_jk[k] -= comz4;
        lhs_4_next_jk[k] += comz1;
    }
}
}
