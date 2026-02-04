#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int j1;
extern int j2;
extern int m;



void loop(){
for (m = 3; m < 5; m++) {
    n = (m - 3 + 1) * 5;
    for (j = grid_points[1] - 3; j >= 0; j--) {
        j1 = j + 1;
        j2 = j1 + 1;
        for (i = 1; i <= grid_points[0] - 2; i++) {
            double *rhs_m_i_j = &rhs[m][i][j][1];
            double *rhs_m_i_j1 = &rhs[m][i][j1][1];
            double *rhs_m_i_j2 = &rhs[m][i][j2][1];
            double *lhs_n3_i_j = &lhs[n + 3][i][j][1];
            double *lhs_n4_i_j = &lhs[n + 4][i][j][1];
            for (k = 1; k <= grid_points[2] - 2; k++) {
                rhs_m_i_j[k] = rhs_m_i_j[k] - lhs_n3_i_j[k] * rhs_m_i_j1[k] - lhs_n4_i_j[k] * rhs_m_i_j2[k];
            }
        }
    }
}
}
