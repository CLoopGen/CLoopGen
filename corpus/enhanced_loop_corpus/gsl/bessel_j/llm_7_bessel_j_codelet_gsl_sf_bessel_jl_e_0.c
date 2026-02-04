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
    double prev_jellp1 = jellp1;
    double prev_jell = jell;
    double prev_jellm1;
    for (ell = l; ell > 0; ell--) {
        prev_jellm1 = -prev_jellp1 + (2 * (ell - 1) + 1) / x * prev_jell;
        double next_val = -prev_jell + (2 * (ell - 2) + 1) / x * prev_jellm1;
        if (ell > 1) {
            prev_jellp1 = prev_jell;
            prev_jell = prev_jellm1;
        }
    }
    jellm1 = prev_jellm1;
    jell = prev_jell;
    jellp1 = prev_jellp1;
}
