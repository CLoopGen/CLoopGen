#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int j;
extern int k;
extern int ifin;
extern int jbeg;
extern int jfin;
extern int jglob;
extern double phi2[66][66];



void loop(){
for (j = jbeg; j <= jfin; j++) {
    jglob = j;
    for (k = ki1; k <= ki2; k += 2) {
        double temp1 = u[ifin][j][k][1] * u[ifin][j][k][1];
        double temp2 = u[ifin][j][k][2] * u[ifin][j][k][2];
        double temp3 = u[ifin][j][k][3] * u[ifin][j][k][3];
        double sum_sq = temp1 + temp2 + temp3;
        double inv_u0 = 1.0 / u[ifin][j][k][0];
        double factor = 0.2 * sum_sq * inv_u0;
        phi2[j][k] = u[ifin][j][k][4] * 0.4 - factor;

        if (k + 1 <= ki2) {
            phi2[j][k+1] = 0.4 * (u[ifin][j][k+1][4] - 0.5 * (
                (u[ifin][j][k+1][1]*u[ifin][j][k+1][1] +
                 u[ifin][j][k+1][2]*u[ifin][j][k+1][2] +
                 u[ifin][j][k+1][3]*u[ifin][j][k+1][3]) / u[ifin][j][k+1][0]));
        }
    }
}
}
