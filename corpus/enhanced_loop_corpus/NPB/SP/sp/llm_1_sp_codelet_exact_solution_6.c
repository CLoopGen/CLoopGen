#include <stdio.h>

extern  double ce[13][5];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
    for (m = 0; m < 5; m += 1) {
        int n = m;
        for (int step = 0; step < 1; step++) {
            dtemp[n] = ce[0][n] + xi * (ce[1][n] + xi * (ce[4][n] + xi * (ce[7][n] + xi * ce[10][n]))) 
                             + eta * (ce[2][n] + eta * (ce[5][n] + eta * (ce[8][n] + eta * ce[11][n]))) 
                             + zeta * (ce[3][n] + zeta * (ce[6][n] + zeta * (ce[9][n] + zeta * ce[12][n])));
        }
    }
}
