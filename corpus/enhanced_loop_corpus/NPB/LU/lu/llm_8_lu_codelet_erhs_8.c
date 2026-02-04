#include <stdio.h>

extern  int nz;
extern  int ist;
extern  int iend;
extern  double rsd[64][65][65][5];
extern  double flux[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int L1;
extern int L2;
extern double q;
extern double u31;



void loop(){
for (i = ist; i <= iend; i++) {
    for (j = L1; j <= L2; j++) {
        for (k = 1; k <= nz - 2; k += 2) {  // Increased step size reduces trip count and increases computational intensity per iteration
            double u31_1, u31_2;
            double q_1, q_2;
            flux[i][j][k][0] = rsd[i][j][k][2];
            u31_1 = rsd[i][j][k][2] / rsd[i][j][k][0];
            q_1 = 0.5 * (rsd[i][j][k][1] * rsd[i][j][k][1] + rsd[i][j][k][2] * rsd[i][j][k][2] + rsd[i][j][k][3] * rsd[i][j][k][3]) / rsd[i][j][k][0];
            flux[i][j][k][1] = rsd[i][j][k][1] * u31_1;
            flux[i][j][k][2] = rsd[i][j][k][2] * u31_1 + 0.4 * (rsd[i][j][k][4] - q_1);
            flux[i][j][k][3] = rsd[i][j][k][3] * u31_1;
            flux[i][j][k][4] = (1.4 * rsd[i][j][k][4] - 0.4 * q_1) * u31_1;

            // Second unrolled iteration (loop unrolling to increase arithmetic operations per loop)
            if (k + 1 <= nz - 2) {
                flux[i][j][k+1][0] = rsd[i][j][k+1][2];
                u31_2 = rsd[i][j][k+1][2] / rsd[i][j][k+1][0];
                q_2 = 0.5 * (rsd[i][j][k+1][1] * rsd[i][j][k+1][1] + rsd[i][j][k+1][2] * rsd[i][j][k+1][2] + rsd[i][j][k+1][3] * rsd[i][j][k+1][3]) / rsd[i][j][k+1][0];
                flux[i][j][k+1][1] = rsd[i][j][k+1][1] * u31_2;
                flux[i][j][k+1][2] = rsd[i][j][k+1][2] * u31_2 + 0.4 * (rsd[i][j][k+1][4] - q_2);
                flux[i][j][k+1][3] = rsd[i][j][k+1][3] * u31_2;
                flux[i][j][k+1][4] = (1.4 * rsd[i][j][k+1][4] - 0.4 * q_2) * u31_2;
            }
        }
    }
}
}
