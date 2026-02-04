#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int ibeg;
extern int ifin;
extern int jbeg;
extern int jfin;
extern int iglob;
extern int jglob;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (i = ibeg; i <= ifin; i += 2) {
    iglob = i;
    for (j = jbeg; j <= jfin; j += 2) {
        jglob = j;
        k = ki1;
        double u0 = u[i][j][k][0];
        double u1 = u[i][j][k][1];
        double u2 = u[i][j][k][2];
        double u3 = u[i][j][k][3];
        double u4 = u[i][j][k][4];
        double kinetic = (u1 * u1 + u2 * u2 + u3 * u3) / u0;
        phi1[i][j] = 0.4 * (u4 - 0.5 * kinetic);
        
        k = ki2;
        u0 = u[i][j][k][0];
        u1 = u[i][j][k][1];
        u2 = u[i][j][k][2];
        u3 = u[i][j][k][3];
        u4 = u[i][j][k][4];
        kinetic = (u1 * u1 + u2 * u2 + u3 * u3) / u0;
        phi2[i][j] = 0.4 * (u4 - 0.5 * kinetic);
    }
}
}
