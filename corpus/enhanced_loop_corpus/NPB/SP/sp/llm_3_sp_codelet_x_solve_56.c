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
for (i = grid_points[0] - 3; i >= 0; i -= 2) {
    i1 = i + 1;
    i2 = i + 2;
    for (m = 0; m < 3; m++) {
        for (j = 1; j <= grid_points[1] - 2; j++) {
            for (k = 1; k <= grid_points[2] - 2; k += 2) {
                double temp_lhs3 = lhs[n + 3][i][j][k];
                double temp_lhs4 = lhs[n + 4][i][j][k];
                double temp_rhs_i1 = rhs[m][i1][j][k];
                double temp_rhs_i2 = rhs[m][i2][j][k];
                rhs[m][i][j][k] -= temp_lhs3 * temp_rhs_i1 + temp_lhs4 * temp_rhs_i2;
                
                if (i > 0 && k < grid_points[2] - 2) {
                    int next_i = i - 1;
                    int next_k = k + 1;
                    int next_i1 = next_i + 1;
                    int next_i2 = next_i + 2;
                    rhs[m][next_i][j][next_k] = rhs[m][next_i][j][next_k] - 
                        lhs[n + 3][next_i][j][next_k] * rhs[m][next_i1][j][next_k] - 
                        lhs[n + 4][next_i][j][next_k] * rhs[m][next_i2][j][next_k];
                }
            }
        }
    }
}
}
