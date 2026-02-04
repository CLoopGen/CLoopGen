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
        double temp_u21[64] = {0}; // Introduce temporary storage to modify dependency pattern
        double temp_q[64] = {0};
        for (k = 1; k < nz - 1; k++) {
            // First pass: compute u21 and q without immediately using them in writes to flux
            temp_u21[k] = rsd[i][j][k][1] / rsd[i][j][k][0];
            double u1 = rsd[i][j][k][1], u2 = rsd[i][j][k][2], u3 = rsd[i][j][k][3];
            temp_q[k] = 0.5 * (u1*u1 + u2*u2 + u3*u3) / rsd[i][j][k][0];
        }
        for (k = 1; k < nz - 1; k++) {
            // Second pass: use precomputed values, removing immediate RAW dependencies
            double r1 = rsd[i][j][k][1], r2 = rsd[i][j][k][2], r4 = rsd[i][j][k][4];
            flux[i][j][k][0] = r1;
            flux[i][j][k][1] = r1 * temp_u21[k] + 0.4 * (r4 - temp_q[k]);
            flux[i][j][k][2] = rsd[i][j][k][2] * temp_u21[k];
            flux[i][j][k][3] = rsd[i][j][k][3] * temp_u21[k];
            flux[i][j][k][4] = (1.4 * r4 - 0.4 * temp_q[k]) * temp_u21[k];
        }
    }
}
}
