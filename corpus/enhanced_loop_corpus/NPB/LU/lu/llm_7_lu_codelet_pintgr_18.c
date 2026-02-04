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
double phi1_local[66][66];
double phi2_local[66][66];
// Eliminate loop-carried dependencies by using local arrays and reverse loop order
for (i = ifin; i >= ibeg; i--) {
    iglob = i;
    for (j = jfin; j >= jbeg; j--) {
        jglob = j;
        // Reverse computation order: now depends on future indices, breaking natural dependency
        int next_i = (i < ifin) ? i + 1 : i;
        int next_j = (j < jfin) ? j + 1 : j;
        
        k = ki1;
        double u0 = u[next_i][next_j][k][0]; // Use next index to break RAW
        double u1 = u[next_i][next_j][k][1];
        double u2 = u[next_i][next_j][k][2];
        double u3 = u[next_i][next_j][k][3];
        double u4 = u[next_i][next_j][k][4];
        double val1 = 0.4 * (u4 - 0.5 * (u1*u1 + u2*u2 + u3*u3) / u0);
        phi1_local[i][j] = val1;

        k = ki2;
        double u0b = u[next_i][next_j][k][0];
        double u1b = u[next_i][next_j][k][1];
        double u2b = u[next_i][next_j][k][2];
        double u3b = u[next_i][next_j][k][3];
        double u4b = u[next_i][next_j][k][4];
        double val2 = 0.4 * (u4b - 0.5 * (u1b*u1b + u2b*u2b + u3b*u3b) / u0b);
        phi2_local[i][j] = val2;
    }
}
// Finalize: copy back to original arrays without dependencies
for (i = ibeg; i <= ifin; i++) {
    for (j = jbeg; j <= jfin; j++) {
        phi1[i][j] = phi1_local[i][j];
        phi2[i][j] = phi2_local[i][j];
    }
}
}
