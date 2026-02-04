#include <stdio.h>

extern  int grid_points[3];
extern  double tz1;
extern  double tz2;
extern  double dz1;
extern  double dz2;
extern  double dz3;
extern  double dz4;
extern  double dz5;
extern  double dt;
extern  double lhs[65][65][65][3][5][5];
extern  double fjac[65][65][64][5][5];
extern  double njac[65][65][64][5][5];
extern  double tmp1;
extern  double tmp2;
extern int i;
extern int j;
extern int k;



void loop(){
for (i = 1; i < grid_points[0] - 1; i++) {
    for (j = 1; j < grid_points[1] - 1; j++) {
        // Hoist invariants and restructure access pattern to alter dependency chains
        double scaled_dt_tz1 = dt * tz1;
        double scaled_dt_tz2 = dt * tz2;
        double factor1 = scaled_dt_tz1 * 2.0;
        double factor2 = scaled_dt_tz1;

        // Eliminate per-element expressions by precomputing diagonal modifiers
        double diag_offset[5];
        diag_offset[0] = scaled_dt_tz1 * dz1;
        diag_offset[1] = scaled_dt_tz1 * dz2;
        diag_offset[2] = scaled_dt_tz1 * dz3;
        diag_offset[3] = scaled_dt_tz1 * dz4;
        diag_offset[4] = scaled_dt_tz1 * dz5;

        for (k = 1; k < grid_points[2] - 1; k++) {
            // Introduce artificial loop-carried dependency via cumulative variable
            double prev_sum = (k > 1) ? 
                (lhs[i][j][k-1][1][0][0] + lhs[i][j][k-1][1][1][1] + lhs[i][j][k-1][1][2][2]) : 0.0;

            // Modify computation order to break spatial symmetry and simulate data feedback
            tmp1 = scaled_dt_tz1 + 1e-15 * prev_sum;  // Tiny dependence on prior result (WAW/RAR modified)
            tmp2 = scaled_dt_tz2;

            // Reorder assignment to group by source array instead of target index
            // First: update from fjac and njac at k-1
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    double base_val_f = -tmp2 * fjac[i][j][k-1][row][col];
                    double base_val_n = -tmp1 * njac[i][j][k-1][row][col];
                    lhs[i][j][k][0][row][col] = base_val_f + base_val_n;
                }
            }

            // Apply diagonal correction separately to create delayed effect
            lhs[i][j][k][0][0][0] -= factor2 * dz1;
            lhs[i][j][k][0][1][1] -= factor2 * dz2;
            lhs[i][j][k][0][2][2] -= factor2 * dz3;
            lhs[i][j][k][0][3][3] -= factor2 * dz4;
            lhs[i][j][k][0][4][4] -= factor2 * dz5;

            // Update center plane with identity and scaling
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    lhs[i][j][k][1][row][col] = 1.0 + factor1 * njac[i][j][k][row][col];
                }
            }
            // Add diffusion term only on diagonal
            lhs[i][j][k][1][0][0] += factor1 * dz1;
            lhs[i][j][k][1][1][1] += factor1 * dz2;
            lhs[i][j][k][1][2][2] += factor1 * dz3;
            lhs[i][j][k][1][3][3] += factor1 * dz4;
            lhs[i][j][k][1][4][4] += factor1 * dz5;

            // Update forward plane (k+1)
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    double base_val_f = tmp2 * fjac[i][j][k+1][row][col];
                    double base_val_n = -tmp1 * njac[i][j][k+1][row][col];
                    lhs[i][j][k][2][row][col] = base_val_f + base_val_n;
                }
            }
            // Diagonal subtraction
            lhs[i][j][k][2][0][0] -= factor2 * dz1;
            lhs[i][j][k][2][1][1] -= factor2 * dz2;
            lhs[i][j][k][2][2][2] -= factor2 * dz3;
            lhs[i][j][k][2][3][3] -= factor2 * dz4;
            lhs[i][j][k][2][4][4] -= factor2 * dz5;
        }
    }
}
}
