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
int step = 2;
for (ell = l; ell > 0; ell -= step) {
    if (ell == 1) {
        jellm1 = -jellp1 + (2 * ell + 1) / x * jell;
        jellp1 = jell;
        jell = jellm1;
        break;
    }
    double factor1 = (2 * ell + 1) / x;
    double factor2 = (2 * (ell - 1) + 1) / x;
    double next_jell = -jellp1 + factor1 * jell;
    jellp1 = jell;
    jell = next_jell;

    double next_next_jell = -jellp1 + factor2 * jell;
    jellp1 = jell;
    jell = next_next_jell;
}
}
