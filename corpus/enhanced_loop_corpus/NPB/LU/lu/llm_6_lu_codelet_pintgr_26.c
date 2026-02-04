#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int j;
extern int k;
extern int ibeg;
extern int jbeg;
extern int jfin;
extern int jglob;
extern double phi1[66][66];



void loop(){
    for (j = jbeg; j <= jfin; j++) {
        jglob = j;
        double temp_sum = 0.0;
        for (k = ki1; k <= ki2; k++) {
            double vx = u[ibeg][j][k][1];
            double vy = u[ibeg][j][k][2];
            double vz = u[ibeg][j][k][3];
            double speed_sq = vx * vx + vy * vy + vz * vz;
            double denom_inv = 1.0 / u[ibeg][j][k][0];
            phi1[j][k] = 0.4 * (u[ibeg][j][k][4] - 0.5 * speed_sq * denom_inv);
            temp_sum += phi1[j][k];
        }
        phi1[j][ki2 + 1] = temp_sum; // Introduce WAW and RAW dependency: write after prior writes, read after write in reduction
    }
}
