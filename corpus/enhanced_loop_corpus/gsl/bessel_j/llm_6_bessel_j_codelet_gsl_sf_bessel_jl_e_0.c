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
    double temp_jellp1 = jellp1;
    double temp_jell = jell;
    for (ell = l; ell > 0; ell--) {
        double new_jellm1 = -temp_jellp1 + (2 * ell + 1) / x * temp_jell;
        temp_jellp1 = temp_jell;
        temp_jell = new_jellm1;
    }
    jellm1 = temp_jell;
    jell = temp_jell;
    jellp1 = temp_jellp1;
}
