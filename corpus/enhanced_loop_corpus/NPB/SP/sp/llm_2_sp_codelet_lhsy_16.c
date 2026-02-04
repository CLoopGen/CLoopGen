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
    for (k = 1; k <= grid_points[2] - 2; k++) {
        // Change memory access pattern to consecutive by unrolling and reordering operations
        double *lhs2_ik = &lhs[2][i][j][k];
        double *lhs3_ik = &lhs[3][i][j][k];
        double *lhs4_ik = &lhs[4][i][j][k];
        double *lhs1_next = &lhs[1][i][j + 1][k];
        double *lhs2_next = &lhs[2][i][j + 1][k];
        double *lhs3_next = &lhs[3][i][j + 1][k];
        double *lhs4_next = &lhs[4][i][j + 1][k];

        lhs2_ik[0] += comz5;
        lhs3_ik[0] -= comz4;
        lhs4_ik[0] += comz1;
        lhs1_next[0] -= comz4;
        lhs2_next[0] += comz6;
        lhs3_next[0] -= comz4;
        lhs4_next[0] += comz1;
    }
}
}
