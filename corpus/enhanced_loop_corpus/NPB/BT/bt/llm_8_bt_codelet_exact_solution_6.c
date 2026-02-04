#include <stdio.h>

extern  double ce[5][13];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m++) {
        double term_x = ce[m][0] + xi * (ce[m][1] + xi * ce[m][4]);
        double term_y = eta * (ce[m][2] + eta * ce[m][5]);
        double term_z = zeta * (ce[m][3] + zeta * ce[m][6]);
        dtemp[m] = term_x + term_y + term_z;
    }
}
