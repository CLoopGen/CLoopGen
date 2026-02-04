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
for (ell = l; ell > 0; ell--) {
    if (x == 0.0) {
        jellm1 = 0.0;
    } else {
        jellm1 = -jellp1 + (2 * ell + 1) / x * jell;
    }
    jellp1 = jell;
    jell = jellm1;
}
}
