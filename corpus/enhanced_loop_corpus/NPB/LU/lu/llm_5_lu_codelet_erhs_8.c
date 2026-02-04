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
        for (k = 1; k <= nz - 2; k++) {
            double rho_inv = 1.0 / rsd[i][j][k][0];
            if (rho_inv > 1e-10 || rho_inv < -1e-10) {
                flux[i][j][k][0] = rsd[i][j][k][2];
                u31 = rsd[i][j][k][2] * rho_inv;
                q = 0.5 * (rsd[i][j][k][1]*rsd[i][j][k][1] + rsd[i][j][k][2]*rsd[i][j][k][2] + rsd[i][j][k][3]*rsd[i][j][k][3]) * rho_inv;
                flux[i][j][k][1] = rsd[i][j][k][1] * u31;
                flux[i][j][k][2] = rsd[i][j][k][2] * u31 + 0.4 * (rsd[i][j][k][4] - q);
                flux[i][j][k][3] = rsd[i][j][k][3] * u31;
                flux[i][j][k][4] = (1.4 * rsd[i][j][k][4] - 0.4 * q) * u31;
            } else {
                continue;
            }
        }
    }
}
}
