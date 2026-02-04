#include <stdio.h>

extern  double ce[13][5];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
for (m = 0; m < 5; m++) {
    dtemp[m] = ce[0][m];
    if (xi > 0.0) {
        dtemp[m] += xi * (ce[1][m] + xi * (ce[4][m] + xi * (ce[7][m] + xi * ce[10][m])));
    }
    if (eta > 0.0) {
        dtemp[m] += eta * (ce[2][m] + eta * (ce[5][m] + eta * (ce[8][m] + eta * ce[11][m])));
    }
    if (zeta > 0.0) {
        dtemp[m] += zeta * (ce[3][m] + zeta * (ce[6][m] + zeta * (ce[9][m] + zeta * ce[12][m])));
    }
}
}
