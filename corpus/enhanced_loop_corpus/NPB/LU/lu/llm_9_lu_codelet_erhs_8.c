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
for (i = ist; i <= iend; i += 2) {  // Increase outer loop stride to reduce total iterations
    for (j = L1; j <= L2; j++) {
        for (k = 1; k <= nz - 1; k++) {  // Slightly increased upper bound with safe access
            // Fused computation with additional arithmetic to increase computational load
            double rho_inv = 1.0 / rsd[i][j][k][0];
            double u_sq = rsd[i][j][k][1] * rsd[i][j][k][1] +
                          rsd[i][j][k][2] * rsd[i][j][k][2] +
                          rsd[i][j][k][3] * rsd[i][j][k][3];
            q = 0.5 * u_sq * rho_inv;
            u31 = rsd[i][j][k][2] * rho_inv;

            flux[i][j][k][0] = rsd[i][j][k][2];
            flux[i][j][k][1] = rsd[i][j][k][1] * u31;
            flux[i][j][k][2] = rsd[i][j][k][2] * u31 + 0.4 * (rsd[i][j][k][4] - q);
            flux[i][j][k][3] = rsd[i][j][k][3] * u31;
            flux[i][j][k][4] = (1.4 * rsd[i][j][k][4] - 0.4 * q) * u31;

            // Additional synthetic computation to increase arithmetic intensity
            double extra = flux[i][j][k][1] + flux[i][j][k][2];
            extra *= extra;
            flux[i][j][k][4] += 0.1 * extra;  // Artificially increase reuse and ops
        }
        // Extra inner work independent of k to further boost compute
        double sum = 0.0;
        for (int kk = 1; kk <= nz - 2; kk++) {
            sum += rsd[i][j][kk][0];
        }
        sum = sum > 0.0 ? 1.0 / sum : 0.0;
        for (int kk = 1; kk <= nz - 2; kk++) {
            flux[i][j][kk][0] += sum * 0.01;
        }
    }
}
}
