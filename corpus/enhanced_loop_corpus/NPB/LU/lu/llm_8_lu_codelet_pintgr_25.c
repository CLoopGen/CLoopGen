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
for (i = ibeg; i <= ifin; i += 2) {
    iglob = i;
    for (k = ki1; k <= ki2; k++) {
        double u0 = u[i][jfin][k][0];
        double u1 = u[i][jfin][k][1];
        double u2 = u[i][jfin][k][2];
        double u3 = u[i][jfin][k][3];
        double u4 = u[i][jfin][k][4];
        double kinetic = (u1 * u1 + u2 * u2 + u3 * u3) / u0;
        phi2[i][k] = 0.4 * (u4 - 0.5 * kinetic);
    }
}
}
