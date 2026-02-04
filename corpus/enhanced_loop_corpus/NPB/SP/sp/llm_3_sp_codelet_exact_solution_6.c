#include <stdio.h>

extern  double ce[13][5];
extern double xi;
extern double eta;
extern double zeta;
extern double dtemp[5];
extern int m;



void loop(){
    // Variant 2: Strided memory access pattern across the 'ce' array
    // Instead of accessing ce[i][m] with i varying per term, we precompute strides
    // and access ce with a fixed stride over the first dimension for each m.

    for (m = 0; m < 5; m++) {
        const double *base = &ce[0][m]; // Base pointer for this m
        dtemp[m] = base[0] 
                 + xi * (base[1] + xi * (base[4] + xi * (base[7] + xi * base[10])))
                 + eta * (base[2] + eta * (base[5] + eta * (base[8] + eta * base[11])))
                 + zeta * (base[3] + zeta * (base[6] + zeta * (base[9] + zeta * base[12])));
    }
}
