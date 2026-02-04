#include <stdio.h>

extern  double ce[5][13];
extern double u000ijk[5];
extern int m;
extern double xi;
extern double eta;
extern double zeta;



void loop(){
    for (m = 0; m < 5; m++) {
        double temp_xi = xi;
        double temp_eta = eta;
        double temp_zeta = zeta;
        double xi2 = temp_xi * temp_xi;
        double eta2 = temp_eta * temp_eta;
        double zeta2 = temp_zeta * temp_zeta;
        double xi3 = xi2 * temp_xi;
        double eta3 = eta2 * temp_eta;
        double zeta3 = zeta2 * temp_zeta;
        double xi4 = xi3 * temp_xi;
        double eta4 = eta3 * temp_eta;
        double zeta4 = zeta3 * temp_zeta;

        u000ijk[m] = ce[m][0] + 
                    ce[m][1] * temp_xi + 
                    ce[m][2] * temp_eta + 
                    ce[m][3] * temp_zeta + 
                    ce[m][4] * xi2 + 
                    ce[m][5] * eta2 + 
                    ce[m][6] * zeta2 + 
                    ce[m][7] * xi3 + 
                    ce[m][8] * eta3 + 
                    ce[m][9] * zeta3 + 
                    ce[m][10] * xi4 + 
                    ce[m][11] * eta4 + 
                    ce[m][12] * zeta4;
    }
}
