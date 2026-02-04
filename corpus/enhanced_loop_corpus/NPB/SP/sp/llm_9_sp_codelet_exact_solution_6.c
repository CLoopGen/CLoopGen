#include <stdio.h>

extern  double ce[13][5];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
for (m = 0; m < 3; m++) {
    double x_part = ce[0][m] + xi * (ce[1][m] + xi * (ce[4][m] + xi * (ce[7][m] + xi * (ce[10][m]))));
    double y_part = eta * (ce[2][m] + eta * (ce[5][m] + eta * (ce[8][m] + eta * (ce[11][m]))));
    double z_part = zeta * (ce[3][m] + zeta * (ce[6][m] + zeta * (ce[9][m] + zeta * (ce[12][m]))));
    dtemp[m] = x_part + y_part + z_part;
    
    // Additional computational work to increase intensity
    dtemp[m] *= dtemp[m];
    dtemp[m] += xi * eta * zeta;
}
}
