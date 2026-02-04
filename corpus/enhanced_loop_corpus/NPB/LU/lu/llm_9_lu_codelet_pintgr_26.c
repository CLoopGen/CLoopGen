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
    for (k = ki1; k <= ki2; k += 2) {
        double u0 = u[ibeg][j][k][0];
        double u1 = u[ibeg][j][k][1];
        double u2 = u[ibeg][j][k][2];
        double u3 = u[ibeg][j][k][3];
        double u4 = u[ibeg][j][k][4];
        double kinetic = (u1*u1 + u2*u2 + u3*u3) * 0.5;
        phi1[j][k] = 0.4 * (u4 - kinetic / u0);
        
        if (k + 1 <= ki2) {
            double u0_next = u[ibeg][j][k+1][0];
            double u1_next = u[ibeg][j][k+1][1];
            double u2_next = u[ibeg][j][k+1][2];
            double u3_next = u[ibeg][j][k+1][3];
            double u4_next = u[ibeg][j][k+1][4];
            double kinetic_next = (u1_next*u1_next + u2_next*u2_next + u3_next*u3_next) * 0.5;
            phi1[j][k+1] = 0.4 * (u4_next - kinetic_next / u0_next);
        }
    }
}
}
