#include <stdio.h>

extern  int nz;
extern  int jst;
extern  int jend;
extern  double rsd[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int L1;
extern int L2;
extern double q;
extern double u21;



void loop(){
for (i = L1; i <= L2; i++) {
    for (j = jst; j <= jend; j++) {
        for (k = 1; k < nz - 1; k += 2) { // Increased loop stride to reduce trip count and increase computational intensity per iteration
            double u21_1, u21_2;
            double q_1, q_2;
            double inv_rsd0_1, inv_rsd0_2;

            // Prefetch and reuse common terms for first k
            inv_rsd0_1 = 1.0 / rsd[i][j][k][0];
            u21_1 = rsd[i][j][k][1] * inv_rsd0_1;
            q_1 = 0.5 * (rsd[i][j][k][1] * rsd[i][j][k][1] + 
                         rsd[i][j][k][2] * rsd[i][j][k][2] + 
                         rsd[i][j][k][3] * rsd[i][j][k][3]) * inv_rsd0_1;

            flux[i][j][k][0] = rsd[i][j][k][1];
            flux[i][j][k][1] = rsd[i][j][k][1] * u21_1 + 0.4 * (rsd[i][j][k][4] - q_1);
            flux[i][j][k][2] = rsd[i][j][k][2] * u21_1;
            flux[i][j][k][3] = rsd[i][j][k][3] * u21_1;
            flux[i][j][k][4] = (1.4 * rsd[i][j][k][4] - 0.4 * q_1) * u21_1;

            // Handle k+1 if within bounds
            if (k + 1 < nz - 1) {
                inv_rsd0_2 = 1.0 / rsd[i][j][k+1][0];
                u21_2 = rsd[i][j][k+1][1] * inv_rsd0_2;
                q_2 = 0.5 * (rsd[i][j][k+1][1] * rsd[i][j][k+1][1] + 
                             rsd[i][j][k+1][2] * rsd[i][j][k+1][2] + 
                             rsd[i][j][k+1][3] * rsd[i][j][k+1][3]) * inv_rsd0_2;

                flux[i][j][k+1][0] = rsd[i][j][k+1][1];
                flux[i][j][k+1][1] = rsd[i][j][k+1][1] * u21_2 + 0.4 * (rsd[i][j][k+1][4] - q_2);
                flux[i][j][k+1][2] = rsd[i][j][k+1][2] * u21_2;
                flux[i][j][k+1][3] = rsd[i][j][k+1][3] * u21_2;
                flux[i][j][k+1][4] = (1.4 * rsd[i][j][k+1][4] - 0.4 * q_2) * u21_2;
            }
        }
    }
}
}
