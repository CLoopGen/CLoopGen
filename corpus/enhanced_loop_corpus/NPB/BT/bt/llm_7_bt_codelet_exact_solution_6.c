#include <stdio.h>

extern  double ce[5][13];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
    double accum[5];
    for (m = 0; m < 5; m++) {
        accum[m] = 0.0;
    }
    for (m = 0; m < 5; m++) {
        accum[m] += ce[m][0];
        accum[m] += xi * ce[m][1];
        accum[m] += xi * xi * ce[m][4];
        accum[m] += xi * xi * xi * ce[m][7];
        accum[m] += xi * xi * xi * xi * ce[m][10];
        accum[m] += eta * ce[m][2];
        accum[m] += eta * eta * ce[m][5];
        accum[m] += eta * eta * eta * ce[m][8];
        accum[m] += eta * eta * eta * eta * ce[m][11];
        accum[m] += zeta * ce[m][3];
        accum[m] += zeta * zeta * ce[m][6];
        accum[m] += zeta * zeta * zeta * ce[m][9];
        accum[m] += zeta * zeta * zeta * zeta * ce[m][12];
        dtemp[m] = accum[m];
    }
}
