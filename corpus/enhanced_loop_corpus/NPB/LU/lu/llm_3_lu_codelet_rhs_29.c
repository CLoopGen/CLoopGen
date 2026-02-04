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
        for (k = 1; k <= nz - 2; k += 2) {
            int k1 = k;
            int k2 = k + 1;
            if (k2 <= nz - 2) {
                // First k index
                flux[i][j][k1][0] = u[i][j][k1][1];
                u21 = u[i][j][k1][1] / u[i][j][k1][0];
                q = 0.5 * (u[i][j][k1][1]*u[i][j][k1][1] + u[i][j][k1][2]*u[i][j][k1][2] + u[i][j][k1][3]*u[i][j][k1][3]) / u[i][j][k1][0];
                flux[i][j][k1][1] = u[i][j][k1][1] * u21 + 0.40000000000000002 * (u[i][j][k1][4] - q);
                flux[i][j][k1][2] = u[i][j][k1][2] * u21;
                flux[i][j][k1][3] = u[i][j][k1][3] * u21;
                flux[i][j][k1][4] = (1.3999999999999999 * u[i][j][k1][4] - 0.40000000000000002 * q) * u21;

                // Second k index (strided access with step 2)
                flux[i][j][k2][0] = u[i][j][k2][1];
                u21 = u[i][j][k2][1] / u[i][j][k2][0];
                q = 0.5 * (u[i][j][k2][1]*u[i][j][k2][1] + u[i][j][k2][2]*u[i][j][k2][2] + u[i][j][k2][3]*u[i][j][k2][3]) / u[i][j][k2][0];
                flux[i][j][k2][1] = u[i][j][k2][1] * u21 + 0.40000000000000002 * (u[i][j][k2][4] - q);
                flux[i][j][k2][2] = u[i][j][k2][2] * u21;
                flux[i][j][k2][3] = u[i][j][k2][3] * u21;
                flux[i][j][k2][4] = (1.3999999999999999 * u[i][j][k2][4] - 0.40000000000000002 * q) * u21;
            } else {
                // Handle odd-sized nz-2 with single computation
                flux[i][j][k1][0] = u[i][j][k1][1];
                u21 = u[i][j][k1][1] / u[i][j][k1][0];
                q = 0.5 * (u[i][j][k1][1]*u[i][j][k1][1] + u[i][j][k1][2]*u[i][j][k1][2] + u[i][j][k1][3]*u[i][j][k1][3]) / u[i][j][k1][0];
                flux[i][j][k1][1] = u[i][j][k1][1] * u21 + 0.40000000000000002 * (u[i][j][k1][4] - q);
                flux[i][j][k1][2] = u[i][j][k1][2] * u21;
                flux[i][j][k1][3] = u[i][j][k1][3] * u21;
                flux[i][j][k1][4] = (1.3999999999999999 * u[i][j][k1][4] - 0.40000000000000002 * q) * u21;
            }
        }
    }
}
}
