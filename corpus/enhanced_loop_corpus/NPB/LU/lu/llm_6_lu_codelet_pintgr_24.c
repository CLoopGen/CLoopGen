#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int i;
extern int k;
extern int ibeg;
extern int ifin;
extern int jbeg;
extern int iglob;
extern double phi1[66][66];



void loop(){
for (i = ibeg; i <= ifin; i++) {
    iglob = i;
    double temp_sum = 0.0;
    for (k = ki1; k <= ki2; k++) {
        double u0 = u[i][jbeg][k][0];
        double u1 = u[i][jbeg][k][1];
        double u2 = u[i][jbeg][k][2];
        double u3 = u[i][jbeg][k][3];
        double u4 = u[i][jbeg][k][4];
        double kinetic = (u1 * u1 + u2 * u2 + u3 * u3) / u0;
        phi1[i][k] = 0.4 * (u4 - 0.5 * kinetic);
        temp_sum += phi1[i][k];
    }
    phi1[i][ki2 + 1] = temp_sum; // Introduce WAW and RAW dependency: write after prior writes, read for accumulation
}
}
