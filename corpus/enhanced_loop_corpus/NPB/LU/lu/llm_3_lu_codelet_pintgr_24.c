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
int stride = 66;
for (k = ki1; k <= ki2; k++) {
    for (i = ibeg; i <= ifin; i++) {
        iglob = i;
        // Change memory access pattern to stride through k first, promoting spatial locality in i
        // Access phi1 with explicit stride and reuse intermediate calculations
        double *u_ptr = &u[i][jbeg][k][0];
        double inv_u0 = 1.0 / u_ptr[0];
        double vel_sq = ((u_ptr[1] * u_ptr[1]) + (u_ptr[2] * u_ptr[2]) + (u_ptr[3] * u_ptr[3])) * inv_u0;
        phi1[i][k] = 0.4 * (u_ptr[4] - 0.5 * vel_sq);
    }
}
}
