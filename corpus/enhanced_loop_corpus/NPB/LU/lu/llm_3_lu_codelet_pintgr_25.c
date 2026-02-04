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
for (k = ki1; k <= ki2; k++) {
    for (i = ibeg; i <= ifin; i++) {
        iglob = i;
        double *u_ptr = &u[i][jfin][k][0];
        phi2[i][k] = 0.4 * (u_ptr[4] - 0.5 * (
            (u_ptr[1] * u_ptr[1]) +
            (u_ptr[2] * u_ptr[2]) +
            (u_ptr[3] * u_ptr[3])
        ) / u_ptr[0]);
    }
}
}
