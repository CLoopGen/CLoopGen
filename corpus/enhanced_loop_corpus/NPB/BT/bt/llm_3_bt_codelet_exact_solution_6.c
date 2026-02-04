#include <stdio.h>

extern  double ce[5][13];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
for (m = 0; m < 5; m++) {
    const int indices[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    dtemp[m] = ce[m][indices[0]] + xi * (ce[m][indices[1]] + xi * (ce[m][indices[4]] + xi * (ce[m][indices[7]] + xi * ce[m][indices[10]]))) + eta * (ce[m][indices[2]] + eta * (ce[m][indices[5]] + eta * (ce[m][indices[8]] + eta * ce[m][indices[11]]))) + zeta * (ce[m][indices[3]] + zeta * (ce[m][indices[6]] + zeta * (ce[m][indices[9]] + zeta * ce[m][indices[12]])));
}
}
