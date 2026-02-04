#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int i1;
extern int i2;
extern int m;



void loop(){
for (m = 3; m < 5; m++) {
    n = (m - 3 + 1) * 5;
    for (i = grid_points[0] - 3; i >= 0; i--) {
        i1 = i + 1;
        i2 = i + 2;
        for (j = 1; j <= grid_points[1] - 2; j++) {
            double *rhs_m_i_j   = &rhs[m][i][j][1];       // Base pointer for consecutive access
            double *lhs_n3_i_j = &lhs[n + 3][i][j][1];
            double *lhs_n4_i_j = &lhs[n + 4][i][j][1];
            double *rhs_m_i1_j = &rhs[m][i1][j][1];
            double *rhs_m_i2_j = &rhs[m][i2][j][1];
            int size_k = grid_points[2] - 2;
            for (k = 0; k < size_k; k++) { // Convert to zero-based, consecutive linear access
                rhs_m_i_j[k] = rhs_m_i_j[k] - lhs_n3_i_j[k] * rhs_m_i1_j[k] - lhs_n4_i_j[k] * rhs_m_i2_j[k];
            }
        }
    }
}
}
