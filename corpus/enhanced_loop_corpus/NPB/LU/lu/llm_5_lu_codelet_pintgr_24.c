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
        if (u[i][jbeg][k][0] > 1e-6) {
            phi1[i][k] = 0.40000000000000002 * (u[i][jbeg][k][4] - 0.5 * (((u[i][jbeg][k][1]) * (u[i][jbeg][k][1])) + ((u[i][jbeg][k][2]) * (u[i][jbeg][k][2])) + ((u[i][jbeg][k][3]) * (u[i][jbeg][k][3]))) / u[i][jbeg][k][0]);
        } else {
            phi1[i][k] = 0.0;
        }
    }
}
}
