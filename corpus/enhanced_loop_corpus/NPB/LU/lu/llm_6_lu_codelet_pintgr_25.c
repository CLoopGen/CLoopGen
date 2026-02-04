#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int i;
extern int k;
extern int ibeg;
extern int ifin;
extern int jfin;
extern int iglob;
extern double phi2[66][66];



void loop(){
for (i = ibeg; i <= ifin; i++) {
    iglob = i;
    double temp_sum = 0.0;
    for (k = ki1; k <= ki2; k++) {
        double u0 = u[i][jfin][k][0];
        double u1 = u[i][jfin][k][1];
        double u2 = u[i][jfin][k][2];
        double u3 = u[i][jfin][k][3];
        double sq_norm = (u1 * u1 + u2 * u2 + u3 * u3);
        phi2[i][k] = 0.4 * (u[i][jfin][k][4] - 0.5 * sq_norm / u0);
        temp_sum += phi2[i][k];
    }
    phi2[i][ki1] += temp_sum * 0.01; // Introduce WAW and RAW dependency: write after prior writes, read after write in reduction
}
}
