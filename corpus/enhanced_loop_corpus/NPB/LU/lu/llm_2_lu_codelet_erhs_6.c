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
            int idx = k;
            flux[i][j][idx][0] = rsd[i][j][idx][1];
            u21 = rsd[i][j][idx][1] / rsd[i][j][idx][0];
            q = 0.5 * (rsd[i][j][idx][1] * rsd[i][j][idx][1] + rsd[i][j][idx][2] * rsd[i][j][idx][2] + rsd[i][j][idx][3] * rsd[i][j][idx][3]) / rsd[i][j][idx][0];
            flux[i][j][idx][1] = rsd[i][j][idx][1] * u21 + 0.40000000000000002 * (rsd[i][j][idx][4] - q);
            flux[i][j][idx][2] = rsd[i][j][idx][2] * u21;
            flux[i][j][idx][3] = rsd[i][j][idx][3] * u21;
            flux[i][j][idx][4] = (1.3999999999999999 * rsd[i][j][idx][4] - 0.40000000000000002 * q) * u21;
        }
    }
}
}
