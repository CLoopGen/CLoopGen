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
    for (k = ki1; k <= ki2 + 1; k++) {
        if (k <= ki2) {
            double temp = u[i][jfin][k][1] * u[i][jfin][k][1] +
                          u[i][jfin][k][2] * u[i][jfin][k][2] +
                          u[i][jfin][k][3] * u[i][jfin][k][3];
            phi2[i][k] = 0.4 * (u[i][jfin][k][4] - 0.5 * temp / u[i][jfin][k][0]);
        } else {
            phi2[i][k] = 0.0;
        }
    }
}
}
