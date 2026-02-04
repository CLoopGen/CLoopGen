#include <stdio.h>

extern  int ki1;
extern  int ki2;
extern  double u[64][65][65][5];
extern int j;
extern int k;
extern int ibeg;
extern int jbeg;
extern int jfin;
extern int jglob;
extern double phi1[66][66];



void loop(){
    double local_phi[65][65]; // Local buffer to eliminate immediate array write (remove WAR/WAW)
    for (j = jbeg; j <= jfin; j++) {
        jglob = j;
        for (k = ki1; k <= ki2; k++) {
            double rho = u[ibeg][j][k][0];
            double e = u[ibeg][j][k][4];
            double ke = (u[ibeg][j][k][1] * u[ibeg][j][k][1] +
                        u[ibeg][j][k][2] * u[ibeg][j][k][2] +
                        u[ibeg][j][k][3] * u[ibeg][j][k][3]) / rho;
            local_phi[j - jbeg][k] = 0.4 * (e - 0.5 * ke); // No direct write to shared phi1 → removes potential WAW across iterations if unrolled
        }
    }
    // Now copy back to phi1 without loop-carried dependencies
    for (j = jbeg; j <= jfin; j++) {
        for (k = ki1; k <= ki2; k++) {
            phi1[j][k] = local_phi[j - jbeg][k]; // Eliminates intra-loop memory dependency on phi1
        }
    }
}
