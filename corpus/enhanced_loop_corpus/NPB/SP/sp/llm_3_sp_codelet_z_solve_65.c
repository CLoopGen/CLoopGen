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
        // Reorder inner loop to access memory consecutively along m first, then k
        double temp_rhs[3];
        for (k = 0; k <= grid_points[2] - 3; k++) {
            k1 = k + 1;
            k2 = k + 2;
            fac1 = 1. / lhs[n + 2][i][j][k];

            // Pre-load rhs values for consecutive access
            for (m = 0; m < 3; m++) {
                temp_rhs[m] = rhs[m][i][j][k];
            }

            // Update with fac1 using local copy
            lhs[n + 3][i][j][k] *= fac1;
            lhs[n + 4][i][j][k] *= fac1;
            for (m = 0; m < 3; m++) {
                temp_rhs[m] *= fac1;
                rhs[m][i][j][k] = temp_rhs[m]; // Store back
            }

            // Use loaded and scaled values for updates at k1
            lhs[n + 2][i][j][k1] -= lhs[n + 1][i][j][k1] * lhs[n + 3][i][j][k];
            lhs[n + 3][i][j][k1] -= lhs[n + 1][i][j][k1] * lhs[n + 4][i][j][k];
            for (m = 0; m < 3; m++) {
                rhs[m][i][j][k1] -= lhs[n + 1][i][j][k1] * temp_rhs[m];
            }

            // Update k2 using original pattern
            lhs[n + 1][i][j][k2] -= lhs[n + 0][i][j][k2] * lhs[n + 3][i][j][k];
            lhs[n + 2][i][j][k2] -= lhs[n + 0][i][j][k2] * lhs[n + 4][i][j][k];
            for (m = 0; m < 3; m++) {
                rhs[m][i][j][k2] -= lhs[n + 0][i][j][k2] * temp_rhs[m];
            }
        }
    }
}
}
