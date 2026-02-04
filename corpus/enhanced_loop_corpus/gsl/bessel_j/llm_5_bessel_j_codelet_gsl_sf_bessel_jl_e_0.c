#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern  double x;
extern double jellp1;
extern double jell;
extern double jellm1;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (l <= 0) {
    return;
}
for (ell = l; ell > 0; ell--) {
    double temp = (2 * ell + 1) / x * jell;
    if (temp > 1e-9 || temp < -1e-9) {
        jellm1 = -jellp1 + temp;
    } else {
        jellm1 = -jellp1;
    }
    jellp1 = jell;
    jell = jellm1;
}
}
