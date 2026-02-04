#include <stdio.h>

extern  double ce[5][13];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m += 2) {
        for (int n = m; n < m + 2 && n < 5; n++) {
            dtemp[n] = ce[n][0] + xi * (ce[n][1] + xi * (ce[n][4] + xi * (ce[n][7] + xi * ce[n][10]))) 
                               + eta * (ce[n][2] + eta * (ce[n][5] + eta * (ce[n][8] + eta * ce[n][11]))) 
                               + zeta * (ce[n][3] + zeta * (ce[n][6] + zeta * (ce[n][9] + zeta * ce[n][12])));
        }
    }
}
