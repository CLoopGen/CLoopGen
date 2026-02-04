#include <stdio.h>

extern  double ce[5][13];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
    for (m = 0; m < 3; m++) {
        double x_part = ce[m][0];
        x_part += xi * (ce[m][1] + xi * (ce[m][4] + xi * (ce[m][7] + xi * ce[m][10])));
        
        double y_part = eta * (ce[m][2] + eta * (ce[m][5] + eta * (ce[m][8] + eta * ce[m][11])));
        
        double z_part = zeta * (ce[m][3] + zeta * (ce[m][6] + zeta * (ce[m][9] + zeta * ce[m][12])));
        
        dtemp[m] = x_part + y_part + z_part;
    }
    for (m = 3; m < 5; m++) {
        dtemp[m] = ce[m][0] + xi * ce[m][1] + eta * ce[m][2] + zeta * ce[m][3];
    }
}
