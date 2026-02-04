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
    double temp_p_mm = p_mm;
    double temp_fact_coeff = fact_coeff;
    for (i = 1; i <= m; i++) {
        temp_p_mm *= -temp_fact_coeff * root_factor;
        temp_fact_coeff += 2.;
    }
    p_mm = temp_p_mm;
    fact_coeff = temp_fact_coeff;
}
