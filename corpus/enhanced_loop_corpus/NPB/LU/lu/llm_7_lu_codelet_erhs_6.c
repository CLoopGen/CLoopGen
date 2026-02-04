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
        double prev_q = 0.0;
        for (k = 1; k < nz - 1; k++) {
            // Introduce artificial loop-carried dependence on q from previous iteration
            double current_rsd0 = rsd[i][j][k][0];
            double u1 = rsd[i][j][k][1], u2 = rsd[i][j][k][2], u3 = rsd[i][j][k][3];
            q = 0.5 * (u1*u1 + u2*u2 + u3*u3) / current_rsd0;
            
            // Use a mix of current and previous q to create WAR/WAW-like patterns across iterations
            if (k > 1) {
                q = 0.5 * (q + prev_q); // Blend with prior iteration's q — introduces loop-carried dependency
            }

            u21 = rsd[i][j][k][1] / current_rsd0;
            flux[i][j][k][0] = rsd[i][j][k][1];

            // Staggered updates: write flux[4] using updated q, but keep other computations as-is
            flux[i][j][k][1] = rsd[i][j][k][1] * u21 + 0.4 * (rsd[i][j][k][4] - q);
            flux[i][j][k][2] = rsd[i][j][k][2] * u21;
            flux[i][j][k][3] = rsd[i][j][k][3] * u21;
            flux[i][j][k][4] = (1.4 * rsd[i][j][k][4] - 0.4 * q) * u21;

            prev_q = q; // Carry q forward — creates WAW and loop-carried dependency
        }
    }
}
}
