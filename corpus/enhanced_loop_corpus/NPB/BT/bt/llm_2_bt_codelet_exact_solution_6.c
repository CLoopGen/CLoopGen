#include <stdio.h>

extern  double ce[5][13];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
for (m = 0; m < 5; m++) {
    int idx = m;
    dtemp[idx] = ce[idx][0] + xi * (ce[idx][1] + xi * (ce[idx][4] + xi * (ce[idx][7] + xi * ce[idx][10]))) + eta * (ce[idx][2] + eta * (ce[idx][5] + eta * (ce[idx][8] + eta * ce[idx][11]))) + zeta * (ce[idx][3] + zeta * (ce[idx][6] + zeta * (ce[idx][9] + zeta * ce[idx][12])));
}
}
