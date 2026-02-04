#include <stdio.h>

extern  int grid_points[3];
extern  double dssp;
extern  double u[5][65][65][65];
extern  double rhs[5][65][65][65];
extern int i;
extern int j;
extern int k;
extern int m;



void loop(){
    for (m = 0; m < 5; m++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k++) {
                int idx = ((m * 65 + i) * 65 + j) * 65 + k;
                int idx_m_i_minus_1 = ((m * 65 + (i - 1)) * 65 + j) * 65 + k;
                int idx_m_i_plus_1 = ((m * 65 + (i + 1)) * 65 + j) * 65 + k;
                int idx_m_i_plus_2 = ((m * 65 + (i + 2)) * 65 + j) * 65 + k;
                rhs[m][i][j][k] = rhs[m][i][j][k] - dssp * (-4. * u[m][i - 1][j][k] + 6. * u[m][i][j][k] - 4. * u[m][i + 1][j][k] + u[m][i + 2][j][k]);
            }
        }
    }
}
