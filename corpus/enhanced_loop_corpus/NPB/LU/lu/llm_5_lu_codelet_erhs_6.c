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
        for (k = 1; k < nz - 1; k++) {
            // Add control dependency: only process even indices
            if ((i + j + k) % 2 != 0) {
                flux[i][j][k][0] = 0.0;
                flux[i][j][k][1] = 0.0;
                flux[i][j][k][2] = 0.0;
                flux[i][j][k][3] = 0.0;
                flux[i][j][k][4] = 0.0;
                continue;
            }
            flux[i][j][k][0] = rsd[i][j][k][1];
            u21 = rsd[i][j][k][1] / rsd[i][j][k][0];
            q = 0.5 * (rsd[i][j][k][1] * rsd[i][j][k][1] + rsd[i][j][k][2] * rsd[i][j][k][2] + rsd[i][j][k][3] * rsd[i][j][k][3]) / rsd[i][j][k][0];
            flux[i][j][k][1] = rsd[i][j][k][1] * u21 + 0.40000000000000002 * (rsd[i][j][k][4] - q);
            flux[i][j][k][2] = rsd[i][j][k][2] * u21;
            flux[i][j][k][3] = rsd[i][j][k][3] * u21;
            flux[i][j][k][4] = (1.3999999999999999 * rsd[i][j][k][4] - 0.40000000000000002 * q) * u21;
        }
    }
}
}
