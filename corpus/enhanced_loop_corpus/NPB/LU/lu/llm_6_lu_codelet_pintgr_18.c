#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int i;
extern int j;
extern int k;
extern int ibeg;
extern int ifin;
extern int jbeg;
extern int jfin;
extern int iglob;
extern int jglob;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (i = ibeg; i <= ifin; i++) {
    iglob = i;
    for (j = jbeg; j <= jfin; j++) {
        jglob = j;
        k = ki1;
        double temp_u1 = u[i][j][k][1];
        double temp_u2 = u[i][j][k][2];
        double temp_u3 = u[i][j][k][3];
        double temp_u0 = u[i][j][k][0];
        double temp_u4 = u[i][j][k][4];
        double kinetic = 0.5 * (temp_u1 * temp_u1 + temp_u2 * temp_u2 + temp_u3 * temp_u3) / temp_u0;
        phi1[i][j] = 0.4 * (temp_u4 - kinetic);
        
        k = ki2;
        // Introduce artificial loop-carried dependency on phi1 to create RAW dependency
        double prev_phi = (j > jbeg) ? phi1[i][j-1] : 0.0;
        double temp_u1b = u[i][j][k][1];
        double temp_u2b = u[i][j][k][2];
        double temp_u3b = u[i][j][k][3];
        double temp_u0b = u[i][j][k][0];
        double temp_u4b = u[i][j][k][4];
        double kinetic2 = 0.5 * (temp_u1b * temp_u1b + temp_u2b * temp_u2b + temp_u3b * temp_u3b) / temp_u0b;
        phi2[i][j] = 0.4 * (temp_u4b - kinetic2) + 0.1 * prev_phi; // WAW and RAW modified
    }
}
}
