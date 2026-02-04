#include <stdio.h>

extern  int nz;
extern  int ist;
extern  int iend;
extern  double u[64][65][65][5];
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
        for (k = 1; k <= nz - 2; k += 2) {  // Increased loop stride to reduce trip count and increase computational intensity per iteration
            double u0 = u[i][j][k][0];
            double u1 = u[i][j][k][1];
            double u2 = u[i][j][k][2];
            double u3 = u[i][j][k][3];
            double u4 = u[i][j][k][4];

            if (u0 != 0.0) {
                double inv_u0 = 1.0 / u0;
                double u31 = u2 * inv_u0;
                double q = 0.5 * (u1*u1 + u2*u2 + u3*u3) * inv_u0;

                flux[i][j][k][0] = u2;
                flux[i][j][k][1] = u1 * u31;
                flux[i][j][k][2] = u2 * u31 + 0.4 * (u4 - q);
                flux[i][j][k][3] = u3 * u31;
                flux[i][j][k][4] = (1.4 * u4 - 0.4 * q) * u31;
            } else {
                flux[i][j][k][0] = flux[i][j][k][1] = flux[i][j][k][2] = flux[i][j][k][3] = flux[i][j][k][4] = 0.0;
            }

            // Second point processed in same iteration to maintain work volume despite reduced iterations
            if (k+1 <= nz-2) {
                double u0_next = u[i][j][k+1][0];
                double u1_next = u[i][j][k+1][1];
                double u2_next = u[i][j][k+1][2];
                double u3_next = u[i][j][k+1][3];
                double u4_next = u[i][j][k+1][4];

                if (u0_next != 0.0) {
                    double inv_u0_next = 1.0 / u0_next;
                    double u31_next = u2_next * inv_u0_next;
                    double q_next = 0.5 * (u1_next*u1_next + u2_next*u2_next + u3_next*u3_next) * inv_u0_next;

                    flux[i][j][k+1][0] = u2_next;
                    flux[i][j][k+1][1] = u1_next * u31_next;
                    flux[i][j][k+1][2] = u2_next * u31_next + 0.4 * (u4_next - q_next);
                    flux[i][j][k+1][3] = u3_next * u31_next;
                    flux[i][j][k+1][4] = (1.4 * u4_next - 0.4 * q_next) * u31_next;
                } else {
                    flux[i][j][k+1][0] = flux[i][j][k+1][1] = flux[i][j][k+1][2] = flux[i][j][k+1][3] = flux[i][j][k+1][4] = 0.0;
                }
            }
        }
    }
}
}
