#include <stdio.h>

extern  double ce[5][13];
extern double u000ijk[5];
extern int m;
extern double xi;
extern double eta;
extern double zeta;



void loop(){
    u000ijk[0] = ce[0][0] + ce[0][1] * xi + ce[0][2] * eta + ce[0][3] * zeta + ce[0][4] * xi * xi + ce[0][5] * eta * eta + ce[0][6] * zeta * zeta + ce[0][7] * xi * xi * xi + ce[0][8] * eta * eta * eta + ce[0][9] * zeta * zeta * zeta + ce[0][10] * xi * xi * xi * xi + ce[0][11] * eta * eta * eta * eta + ce[0][12] * zeta * zeta * zeta * zeta;
    for (m = 1; m < 5; m++) {
        u000ijk[m] = u000ijk[m-1] + ce[m][0] + ce[m][1] * xi + ce[m][2] * eta + ce[m][3] * zeta + ce[m][4] * xi * xi + ce[m][5] * eta * eta + ce[m][6] * zeta * zeta + ce[m][7] * xi * xi * xi + ce[m][8] * eta * eta * eta + ce[m][9] * zeta * zeta * zeta + ce[m][10] * xi * xi * xi * xi + ce[m][11] * eta * eta * eta * eta + ce[m][12] * zeta * zeta * zeta * zeta;
    }
}
