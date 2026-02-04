#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int l;
extern  int m;
extern  double x;
extern double p_ellm2;
extern double p_ellm1;
extern double p_ell;
extern int ell;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (ell = m + 2; ell <= l; ell++) {
    p_ell = (x * (2 * ell - 1) * p_ellm1 - (ell + m - 1) * p_ellm2) / (ell - m);
    p_ellm2 = p_ellm1;
    p_ellm1 = p_ell;
}

}
