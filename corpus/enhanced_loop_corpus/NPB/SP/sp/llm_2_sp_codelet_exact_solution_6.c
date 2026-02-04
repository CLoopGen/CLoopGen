#include <stdio.h>

extern  double ce[13][5];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
    // Variant 1: Consecutive memory access by restructuring array layout access
    // Here, we simulate consecutive access by unrolling and reordering computations
    // to emphasize spatial locality in dtemp and ce accesses.

    double xi2 = xi * xi;
    double xi3 = xi2 * xi;
    double eta2 = eta * eta;
    double eta3 = eta2 * eta;
    double zeta2 = zeta * zeta;
    double zeta3 = zeta2 * zeta;

    for (m = 0; m < 5; m++) {
        dtemp[m] = ce[0][m] 
                 + xi * ce[1][m]  + xi2 * ce[4][m]  + xi3 * ce[7][m]  + xi2 * xi * xi * ce[10][m]
                 + eta * ce[2][m] + eta2 * ce[5][m] + eta3 * ce[8][m] + eta2 * eta * eta * ce[11][m]
                 + zeta * ce[3][m] + zeta2 * ce[6][m] + zeta3 * ce[9][m] + zeta2 * zeta * zeta * ce[12][m];
    }
}
