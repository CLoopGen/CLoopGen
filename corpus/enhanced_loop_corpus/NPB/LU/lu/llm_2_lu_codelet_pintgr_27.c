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
    for (k = ki1; k <= ki2; k++) {
        int idx_k = k - ki1; // Base index for strided access in k dimension
        double temp_u0 = u[ifin][j][k][0];
        double temp_u1 = u[ifin][j][k][1];
        double temp_u2 = u[ifin][j][k][2];
        double temp_u3 = u[ifin][j][k][3];
        double temp_u4 = u[ifin][j][k][4];
        phi2[j][k] = 0.4 * (temp_u4 - 0.5 * ((temp_u1 * temp_u1) + (temp_u2 * temp_u2) + (temp_u3 * temp_u3)) / temp_u0);
    }
}
}
