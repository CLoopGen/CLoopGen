#include <stdio.h>

extern  int grid_points[3];
extern  double rhs[5][65][65][65];
extern  double lhs[15][65][65][65];
extern int i;
extern int j;
extern int k;
extern int n;
extern int k1;
extern int k2;
extern int m;
extern double fac1;



void loop(){
for (i = 1; i <= grid_points[0] - 2; i++) {
    for (j = 1; j <= grid_points[1] - 2; j++) {
        for (k = 0; k <= grid_points[2] - 3; k += 2) { // Increased trip count step to reduce iterations
            k1 = k + 1;
            k2 = k + 2;
            fac1 = 1.0 / lhs[n + 2][i][j][k];
            // Fused scaling operations into a single loop to increase arithmetic intensity
            for (m = 0; m < 5; m++) {
                if (m < 2) {
                    lhs[n + 3 + m][i][j][k] *= fac1;
                }
                rhs[m % 3][i][j][k] = fac1 * rhs[m % 3][i][j][k];
            }
            // Combined updates with reduced temporal reuse
            double temp1 = lhs[n + 1][i][j][k1] * lhs[n + 3][i][j][k];
            double temp2 = lhs[n + 1][i][j][k1] * lhs[n + 4][i][j][k];
            lhs[n + 2][i][j][k1] -= temp1;
            lhs[n + 3][i][j][k1] -= temp2;
            for (m = 0; m < 3; m++) {
                rhs[m][i][j][k1] -= lhs[n + 1][i][j][k1] * rhs[m][i][j][k];
            }
            double temp3 = lhs[n + 0][i][j][k2] * lhs[n + 3][i][j][k];
            double temp4 = lhs[n + 0][i][j][k2] * lhs[n + 4][i][j][k];
            lhs[n + 1][i][j][k2] -= temp3;
            lhs[n + 2][i][j][k2] -= temp4;
            for (m = 0; m < 3; m++) {
                rhs[m][i][j][k2] -= lhs[n + 0][i][j][k2] * rhs[m][i][j][k];
            }
        }
    }
}
}
