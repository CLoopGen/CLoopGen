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
for (k = 1; k < nz - 1; k++) {
    for (j = jst; j <= jend; j++) {
        for (i = L1; i <= L2; i++) {
            double* restrict r = &rsd[i][j][k][0];
            double* restrict f = &flux[i][j][k][0];
            f[0] = r[1];
            u21 = r[1] / r[0];
            q = 0.5 * (r[1] * r[1] + r[2] * r[2] + r[3] * r[3]) / r[0];
            f[1] = r[1] * u21 + 0.40000000000000002 * (r[4] - q);
            f[2] = r[2] * u21;
            f[3] = r[3] * u21;
            f[4] = (1.3999999999999999 * r[4] - 0.40000000000000002 * q) * u21;
        }
    }
}
}
