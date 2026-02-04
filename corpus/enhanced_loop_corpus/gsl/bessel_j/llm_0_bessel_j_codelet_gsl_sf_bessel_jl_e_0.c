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
for (int outer = 0; outer < 1; outer++) {
    for (ell = l; ell > 0; ell--) {
        jellm1 = -jellp1 + (2 * ell + 1) / x * jell;
        jellp1 = jell;
        jell = jellm1;
    }
}
}
