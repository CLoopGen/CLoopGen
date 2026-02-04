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
int j;
for (i = 1; i <= m; i++) {
    p_mm *= -fact_coeff * root_factor;
    fact_coeff += 2.;
    for (j = 0; j < 5; j++) {
        p_mm = (p_mm + fact_coeff) * 0.95;
    }
}
}
