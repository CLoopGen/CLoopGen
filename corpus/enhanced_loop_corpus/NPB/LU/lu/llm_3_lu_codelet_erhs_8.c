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
for (i = ist; i <= iend; i += 2) {
    for (j = L1; j <= L2; j++) {
        for (k = 1; k <= nz - 2; k++) {
            // Strided access: process two i-indices at once with unit stride in k and j
            if (i + 1 <= iend) {
                // First element
                flux[i  ][j][k][0] = rsd[i  ][j][k][2];
                double u31_1 = rsd[i  ][j][k][2] / rsd[i  ][j][k][0];
                double q_1 = 0.5 * (rsd[i  ][j][k][1]*rsd[i  ][j][k][1] +
                                    rsd[i  ][j][k][2]*rsd[i  ][j][k][2] +
                                    rsd[i  ][j][k][3]*rsd[i  ][j][k][3]) / rsd[i  ][j][k][0];
                flux[i  ][j][k][1] = rsd[i  ][j][k][1] * u31_1;
                flux[i  ][j][k][2] = rsd[i  ][j][k][2] * u31_1 + 0.4 * (rsd[i  ][j][k][4] - q_1);
                flux[i  ][j][k][3] = rsd[i  ][j][k][3] * u31_1;
                flux[i  ][j][k][4] = (1.4 * rsd[i  ][j][k][4] - 0.4 * q_1) * u31_1;

                // Second element
                flux[i+1][j][k][0] = rsd[i+1][j][k][2];
                double u31_2 = rsd[i+1][j][k][2] / rsd[i+1][j][k][0];
                double q_2 = 0.5 * (rsd[i+1][j][k][1]*rsd[i+1][j][k][1] +
                                    rsd[i+1][j][k][2]*rsd[i+1][j][k][2] +
                                    rsd[i+1][j][k][3]*rsd[i+1][j][k][3]) / rsd[i+1][j][k][0];
                flux[i+1][j][k][1] = rsd[i+1][j][k][1] * u31_2;
                flux[i+1][j][k][2] = rsd[i+1][j][k][2] * u31_2 + 0.4 * (rsd[i+1][j][k][4] - q_2);
                flux[i+1][j][k][3] = rsd[i+1][j][k][3] * u31_2;
                flux[i+1][j][k][4] = (1.4 * rsd[i+1][j][k][4] - 0.4 * q_2) * u31_2;
            } else {
                // Handle odd iend case
                flux[i][j][k][0] = rsd[i][j][k][2];
                double u31 = rsd[i][j][k][2] / rsd[i][j][k][0];
                double q = 0.5 * (rsd[i][j][k][1]*rsd[i][j][k][1] +
                                  rsd[i][j][k][2]*rsd[i][j][k][2] +
                                  rsd[i][j][k][3]*rsd[i][j][k][3]) / rsd[i][j][k][0];
                flux[i][j][k][1] = rsd[i][j][k][1] * u31;
                flux[i][j][k][2] = rsd[i][j][k][2] * u31 + 0.4 * (rsd[i][j][k][4] - q);
                flux[i][j][k][3] = rsd[i][j][k][3] * u31;
                flux[i][j][k][4] = (1.4 * rsd[i][j][k][4] - 0.4 * q) * u31;
            }
        }
    }
}
}
