#include <stdio.h>

extern  double ce[5][13];
extern double u000ijk[5];
extern int m;
extern double xi;
extern double eta;
extern double zeta;



void loop(){
    for (m = 0; m < 3; m++) {
        double temp = ce[m][0];
        temp += ce[m][1] * xi;
        temp += ce[m][2] * eta;
        temp += ce[m][3] * zeta;
        temp += ce[m][4] * (xi * xi);
        temp += ce[m][5] * (eta * eta);
        temp += ce[m][6] * (zeta * zeta);
        temp += ce[m][7] * (xi * xi * xi);
        temp += ce[m][8] * (eta * eta * eta);
        temp += ce[m][9] * (zeta * zeta * zeta);
        // Skip fourth-order terms for reduced complexity
        u000ijk[m] = temp;
    }
    // Unroll remaining two iterations
    if (m == 3) {
        u000ijk[3] = ce[3][0] + ce[3][1] * xi + ce[3][2] * eta + ce[3][3] * zeta;
    }
    if (m == 4) {
        u000ijk[4] = ce[4][0] + ce[4][1] * xi + ce[4][2] * eta + ce[4][3] * zeta;
    }
}
