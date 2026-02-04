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
    for (k = ki1; k <= ki2; k++) {
        int idx = k * 65 + i; // Row-major linearization of [i][k] access
        double temp_u0 = u[i][jbeg][k][0];
        double temp_u1 = u[i][jbeg][k][1];
        double temp_u2 = u[i][jbeg][k][2];
        double temp_u3 = u[i][jbeg][k][3];
        double temp_u4 = u[i][jbeg][k][4];
        phi1[i][k] = 0.4 * (temp_u4 - 0.5 * ((temp_u1 * temp_u1) + (temp_u2 * temp_u2) + (temp_u3 * temp_u3)) / temp_u0);
    }
}
}
