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
        k = 1;
        while (k <= nz - 2) {
            flux[i][j][k][0] = u[i][j][k][1];
            u21 = u[i][j][k][1] / u[i][j][k][0];
            q = 0.5 * (u[i][j][k][1]*u[i][j][k][1] + u[i][j][k][2]*u[i][j][k][2] + u[i][j][k][3]*u[i][j][k][3]) / u[i][j][k][0];
            flux[i][j][k][1] = u[i][j][k][1] * u21 + 0.4 * (u[i][j][k][4] - q);
            flux[i][j][k][2] = u[i][j][k][2] * u21;
            flux[i][j][k][3] = u[i][j][k][3] * u21;
            flux[i][j][k][4] = (1.4 * u[i][j][k][4] - 0.4 * q) * u21;
            k += 3;
        }
    }
}
}
