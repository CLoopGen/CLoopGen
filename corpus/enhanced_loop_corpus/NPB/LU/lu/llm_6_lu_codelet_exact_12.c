#include <stdio.h>

extern  double ce[5][13];
extern double u000ijk[5];
extern int m;
extern double xi;
extern double eta;
extern double zeta;



void loop(){
    double temp[5];
    for (m = 0; m < 5; m++) {
        temp[m] = ce[m][0];
        temp[m] += ce[m][1] * xi;
        temp[m] += ce[m][2] * eta;
        temp[m] += ce[m][3] * zeta;
        temp[m] += ce[m][4] * xi * xi;
        temp[m] += ce[m][5] * eta * eta;
        temp[m] += ce[m][6] * zeta * zeta;
        temp[m] += ce[m][7] * xi * xi * xi;
        temp[m] += ce[m][8] * eta * eta * eta;
        temp[m] += ce[m][9] * zeta * zeta * zeta;
        temp[m] += ce[m][10] * xi * xi * xi * xi;
        temp[m] += ce[m][11] * eta * eta * eta * eta;
        temp[m] += ce[m][12] * zeta * zeta * zeta * zeta;
        u000ijk[m] = temp[m];
    }
}
