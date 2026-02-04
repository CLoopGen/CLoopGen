#include <stdio.h>

extern  int nz;
extern  int jst;
extern  int jend;
extern  double u[64][65][65][5];
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
        double temp_u21[64], temp_q[64];
        for (k = 1; k <= nz - 2; k++) {
            flux[i][j][k][0] = u[i][j][k][1];
            temp_u21[k] = u[i][j][k][1] / u[i][j][k][0];
            double u1 = u[i][j][k][1], u2 = u[i][j][k][2], u3 = u[i][j][k][3], u0 = u[i][j][k][0], e = u[i][j][k][4];
            temp_q[k] = 0.5 * (u1 * u1 + u2 * u2 + u3 * u3) / u0;
        }
        for (k = 1; k <= nz - 2; k++) {
            u21 = temp_u21[k];
            q = temp_q[k];
            flux[i][j][k][1] = u[i][j][k][1] * u21 + 0.4 * (u[i][j][k][4] - q);
            flux[i][j][k][2] = u[i][j][k][2] * u21;
            flux[i][j][k][3] = u[i][j][k][3] * u21;
            flux[i][j][k][4] = (1.4 * u[i][j][k][4] - 0.4 * q) * u21;
        }
    }
}
}
