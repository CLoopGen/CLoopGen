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
double prev_phi = 0.0;
for (j = jbeg; j <= jfin; j++) {
    jglob = j;
    for (k = ki1; k <= ki2; k++) {
        // Introduce artificial dependence on previous iteration: RAW hazard
        // phi2 from prior (j,k) now influences current computation
        double base_val = u[ifin][j][k][4];
        double kinetic = ((u[ifin][j][k][1]) * (u[ifin][j][k][1])) +
                         ((u[ifin][j][k][2]) * (u[ifin][j][k][2])) +
                         ((u[ifin][j][k][3]) * (u[ifin][j][k][3]));
        double internal_energy = base_val - 0.5 * kinetic / u[ifin][j][k][0];
        
        // Create loop-carried dependence: current output depends on last phi2 value
        phi2[j][k] = 0.4 * internal_energy + 0.05 * prev_phi;
        
        // Update prev_phi for next iteration (forward dependence)
        prev_phi = phi2[j][k];
    }
}
// Eliminate any leftover dependencies beyond loop scope
prev_phi = 0.0;
}
