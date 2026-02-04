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
    for (k = ki1; k <= ki2; k += 2) {
        double temp1 = u[i][jbeg][k][1] * u[i][jbeg][k][1];
        double temp2 = u[i][jbeg][k][2] * u[i][jbeg][k][2];
        double temp3 = u[i][jbeg][k][3] * u[i][jbeg][k][3];
        double sum_sq = temp1 + temp2 + temp3;
        double denom_inv = 1.0 / u[i][jbeg][k][0];
        double factor = 0.4 * (u[i][jbeg][k][4] - 0.5 * sum_sq * denom_inv);
        phi1[i][k] = factor;
        if (k + 1 <= ki2) {
            phi1[i][k+1] = 0.4 * (u[i][jbeg][k+1][4] - 0.5 * ((u[i][jbeg][k+1][1]*u[i][jbeg][k+1][1] + 
                                   u[i][jbeg][k+1][2]*u[i][jbeg][k+1][2] + 
                                   u[i][jbeg][k+1][3]*u[i][jbeg][k+1][3]) / u[i][jbeg][k+1][0]));
        }
    }
}
}
