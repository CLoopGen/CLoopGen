#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int m;
extern double p_mm;
extern double root_factor;
extern double fact_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 1; j <= m; j++) {
    if (j % 2 == 1) {
        p_mm *= -fact_coeff * root_factor;
        fact_coeff += 2.;
    }
}
}
