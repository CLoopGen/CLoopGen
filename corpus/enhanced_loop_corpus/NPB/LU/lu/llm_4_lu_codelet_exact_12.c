#include <stdio.h>

extern  double ce[5][13];
extern double u000ijk[5];
extern int m;
extern double xi;
extern double eta;
extern double zeta;



void loop(){
    for (m = 0; m < 5; m++) {
        if (m % 2 == 0) {
            u000ijk[m] = ce[m][0] + ce[m][1] * xi + ce[m][2] * eta + ce[m][3] * zeta;
        } else {
            u000ijk[m] = ce[m][4] * xi * xi + ce[m][5] * eta * eta + ce[m][6] * zeta * zeta + 
                        ce[m][7] * xi * xi * xi + ce[m][8] * eta * eta * eta + ce[m][9] * zeta * zeta * zeta + 
                        ce[m][10] * xi * xi * xi * xi + ce[m][11] * eta * eta * eta * eta + ce[m][12] * zeta * zeta * zeta * zeta;
        }
    }
}
