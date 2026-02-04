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
for (j = jbeg; j <= jfin; j += 2) {
    jglob = j;
    for (k = ki1; k <= ki2; k++) {
        double temp1 = u[ibeg][j][k][1];
        double temp2 = u[ibeg][j][k][2];
        double temp3 = u[ibeg][j][k][3];
        double vsq = temp1 * temp1 + temp2 * temp2 + temp3 * temp3;
        double rho_inv = 1.0 / u[ibeg][j][k][0];
        phi1[j][k] = 0.4 * (u[ibeg][j][k][4] - 0.5 * vsq * rho_inv);
    }
}
}
