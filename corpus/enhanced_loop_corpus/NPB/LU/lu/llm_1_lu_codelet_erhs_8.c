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
    for (k = 1; k <= nz - 2; k++) {
        for (j = L1; j <= L2; j++) {
            flux[i][j][k][0] = rsd[i][j][k][2];
            u31 = rsd[i][j][k][2] / rsd[i][j][k][0];
            q = 0.5 * (rsd[i][j][k][1] * rsd[i][j][k][1] + rsd[i][j][k][2] * rsd[i][j][k][2] + rsd[i][j][k][3] * rsd[i][j][k][3]) / rsd[i][j][k][0];
            flux[i][j][k][1] = rsd[i][j][k][1] * u31;
            flux[i][j][k][2] = rsd[i][j][k][2] * u31 + 0.40000000000000002 * (rsd[i][j][k][4] - q);
            flux[i][j][k][3] = rsd[i][j][k][3] * u31;
            flux[i][j][k][4] = (1.3999999999999999 * rsd[i][j][k][4] - 0.40000000000000002 * q) * u31;
        }
    }
}
}
