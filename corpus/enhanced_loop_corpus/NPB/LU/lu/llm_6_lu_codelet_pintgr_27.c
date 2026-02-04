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
    double temp_sum = 0.0;
    for (k = ki1; k <= ki2; k++) {
        double u0 = u[ifin][j][k][0];
        double u1 = u[ifin][j][k][1];
        double u2 = u[ifin][j][k][2];
        double u3 = u[ifin][j][k][3];
        double u4 = u[ifin][j][k][4];
        double velocity_sq = (u1 * u1 + u2 * u2 + u3 * u3) / u0;
        phi2[j][k] = 0.4 * (u4 - 0.5 * velocity_sq);
        temp_sum += phi2[j][k];
    }
    // Introduce loop-carried dependency via temp_sum (WAW and RAW)
    // This creates a reduction-like pattern that carries value across iterations
    if (j > jbeg) {
        phi2[j][ki1] += temp_sum * 0.1;
    }
}
}
