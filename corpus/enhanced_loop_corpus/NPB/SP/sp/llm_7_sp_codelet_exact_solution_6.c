#include <stdio.h>

extern  double ce[13][5];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
    dtemp[0] = ce[0][0] + xi * (ce[1][0] + xi * (ce[4][0] + xi * (ce[7][0] + xi * ce[10][0]))) + eta * (ce[2][0] + eta * (ce[5][0] + eta * (ce[8][0] + eta * ce[11][0]))) + zeta * (ce[3][0] + zeta * (ce[6][0] + zeta * (ce[9][0] + zeta * ce[12][0])));
    for (m = 1; m < 5; m++) {
        dtemp[m] = dtemp[m-1] + ce[0][m] + xi * (ce[1][m] + xi * (ce[4][m] + xi * (ce[7][m] + xi * ce[10][m]))) + eta * (ce[2][m] + eta * (ce[5][m] + eta * (ce[8][m] + eta * ce[11][m]))) + zeta * (ce[3][m] + zeta * (ce[6][m] + zeta * (ce[9][m] + zeta * ce[12][m])));
    }
}
