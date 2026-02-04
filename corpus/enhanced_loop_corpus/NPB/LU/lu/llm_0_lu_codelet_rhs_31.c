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
        for (k = 1; k <= nz - 2; k++) {
            flux[i][j][k][0] = u[i][j][k][2];
            u31 = u[i][j][k][2] / u[i][j][k][0];
            q = 0.5 * (u[i][j][k][1] * u[i][j][k][1] + u[i][j][k][2] * u[i][j][k][2] + u[i][j][k][3] * u[i][j][k][3]) / u[i][j][k][0];
            flux[i][j][k][1] = u[i][j][k][1] * u31;
            flux[i][j][k][2] = u[i][j][k][2] * u31 + 0.40000000000000002 * (u[i][j][k][4] - q);
            flux[i][j][k][3] = u[i][j][k][3] * u31;
            flux[i][j][k][4] = (1.3999999999999999 * u[i][j][k][4] - 0.40000000000000002 * q) * u31;
        }
    }
}
}
