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
        for (k = 2; k < nz - 2; k++) { // Reduced trip count by tightening bounds, increasing work per active iteration
            double u21_center, q_center;
            double u21_prev, u21_next;
            double q_prev, q_next;

            // Compute current point
            u21_center = rsd[i][j][k][1] / rsd[i][j][k][0];
            q_center = 0.5 * (rsd[i][j][k][1]*rsd[i][j][k][1] + 
                               rsd[i][j][k][2]*rsd[i][j][k][2] + 
                               rsd[i][j][k][3]*rsd[i][j][k][3]) / rsd[i][j][k][0];

            flux[i][j][k][0] = rsd[i][j][k][1];
            flux[i][j][k][1] = rsd[i][j][k][1] * u21_center + 0.4 * (rsd[i][j][k][4] - q_center);
            flux[i][j][k][2] = rsd[i][j][k][2] * u21_center;
            flux[i][j][k][3] = rsd[i][j][k][3] * u21_center;
            flux[i][j][k][4] = (1.4 * rsd[i][j][k][4] - 0.4 * q_center) * u21_center;

            // Additional computation: ghost or lookahead update using neighboring k-1 and k+1
            u21_prev = rsd[i][j][k-1][1] / rsd[i][j][k-1][0];
            q_prev = 0.5 * (rsd[i][j][k-1][1]*rsd[i][j][k-1][1] + 
                            rsd[i][j][k-1][2]*rsd[i][j][k-1][2] + 
                            rsd[i][j][k-1][3]*rsd[i][j][k-1][3]) / rsd[i][j][k-1][0];
            flux[i][j][k-1][4] += 0.1 * (1.4 * rsd[i][j][k-1][4] - 0.4 * q_prev) * u21_prev; // Partial correction

            u21_next = rsd[i][j][k+1][1] / rsd[i][j][k+1][0];
            q_next = 0.5 * (rsd[i][j][k+1][1]*rsd[i][j][k+1][1] + 
                            rsd[i][j][k+1][2]*rsd[i][j][k+1][2] + 
                            rsd[i][j][k+1][3]*rsd[i][j][k+1][3]) / rsd[i][j][k+1][0];
            flux[i][j][k+1][1] += 0.1 * (rsd[i][j][k+1][1] * u21_next + 0.4 * (rsd[i][j][k+1][4] - q_next)); // Smoothing contribution
        }
    }
}
}
