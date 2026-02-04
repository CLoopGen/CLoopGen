#include <stdio.h>

extern  double ce[5][13];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;

void loop(){
for (m = 0; m < 5; m++) {
    dtemp[m] = ce[m][0] + xi * (ce[m][1] + xi * (ce[m][4] + xi * (ce[m][7] + xi * ce[m][10]))) + eta * (ce[m][2] + eta * (ce[m][5] + eta * (ce[m][8] + eta * ce[m][11]))) + zeta * (ce[m][3] + zeta * (ce[m][6] + zeta * (ce[m][9] + zeta * ce[m][12])));
}

}
