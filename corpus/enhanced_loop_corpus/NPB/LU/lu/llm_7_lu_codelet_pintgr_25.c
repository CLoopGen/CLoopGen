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
double prev_phi = 0.0;
for (i = ibeg; i <= ifin; i++) {
    iglob = i;
    for (k = ki1; k <= ki2; k++) {
        double local_factor = (u[i][jfin][k][1] + u[i][jfin][k][2]) * 0.1;
        // Remove direct use of u[i][jfin][k][0] in denominator by fusing computation; introduces temporary reuse (WAW on local_factor)
        double pressure = u[i][jfin][k][4] - 0.5 * ((u[i][jfin][k][1]*u[i][jfin][k][1]) + 
                                                    (u[i][jfin][k][2]*u[i][jfin][k][2]) + 
                                                    (u[i][jfin][k][3]*u[i][jfin][k][3])) * local_factor;
        // Introduce loop-carried dependency: current phi2 depends on previous iteration's value
        if (k == ki1) {
            phi2[i][k] = 0.4 * pressure; // base case
        } else {
            phi2[i][k] = 0.4 * pressure + 0.1 * phi2[i][k-1]; // RAW dependency: read from previous iteration
        }
        prev_phi = phi2[i][k]; // used to create artificial dependence across i iterations (though not carried directly)
    }
}
}
