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
    double local_factor = fact_coeff;
    for (i = 1; i <= m; i++) {
        p_mm = p_mm * (-local_factor * root_factor);
        local_factor += 2.;
    }
    fact_coeff = local_factor;
}
