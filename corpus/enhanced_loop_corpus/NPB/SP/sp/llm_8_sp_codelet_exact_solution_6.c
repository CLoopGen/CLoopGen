#include <stdio.h>

extern  double ce[13][5];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
for (m = 0; m < 5; m++) {
    double term_x = ce[0][m] + xi * (ce[1][m] + xi * ce[4][m]);
    double term_y = eta * (ce[2][m] + eta * ce[5][m]);
    double term_z = zeta * (ce[3][m] + zeta * ce[6][m]);
    dtemp[m] = term_x + term_y + term_z;
}
}
