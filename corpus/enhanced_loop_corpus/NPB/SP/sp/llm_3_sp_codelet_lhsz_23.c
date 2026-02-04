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
for (i = 1; i <= grid_points[0] - 2; i += 2) {
    for (j = 1; j <= grid_points[1] - 2; j += 2) {
        double *lhs0_ik = lhs[0][i][j];
        double *lhs1_ik = lhs[1][i][j];
        double *lhs2_ik = lhs[2][i][j];
        double *lhs3_ik = lhs[3][i][j];
        
        lhs0_ik[k] += comz1;
        lhs1_ik[k] -= comz4;
        lhs2_ik[k] += comz6;
        lhs3_ik[k] -= comz4;
        lhs0_ik[k + 1] += comz1;
        lhs1_ik[k + 1] -= comz4;
        lhs2_ik[k + 1] += comz5;

        if (j + 1 <= grid_points[1] - 2) {
            double *lhs0_ij1 = lhs[0][i][j+1];
            double *lhs1_ij1 = lhs[1][i][j+1];
            double *lhs2_ij1 = lhs[2][i][j+1];
            double *lhs3_ij1 = lhs[3][i][j+1];

            lhs0_ij1[k] += comz1;
            lhs1_ij1[k] -= comz4;
            lhs2_ij1[k] += comz6;
            lhs3_ij1[k] -= comz4;
            lhs0_ij1[k + 1] += comz1;
            lhs1_ij1[k + 1] -= comz4;
            lhs2_ij1[k + 1] += comz5;
        }
    }
    if (i + 1 <= grid_points[0] - 2) {
        for (int j_inner = 1; j_inner <= grid_points[1] - 2; j_inner++) {
            lhs[0][i+1][j_inner][k] += comz1;
            lhs[1][i+1][j_inner][k] -= comz4;
            lhs[2][i+1][j_inner][k] += comz6;
            lhs[3][i+1][j_inner][k] -= comz4;
            lhs[0][i+1][j_inner][k+1] += comz1;
            lhs[1][i+1][j_inner][k+1] -= comz4;
            lhs[2][i+1][j_inner][k+1] += comz5;
        }
    }
}
}
