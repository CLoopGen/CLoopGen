#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern double aa;
extern double term;
extern int ii;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_sum = 0.0;
double temp_factor;
for (ii = 0; ii < 2 * n1; ii++) {
    temp_factor = (double)(ii + 1) * (ii + 1);
    temp_sum += qq * qq / (aa - 4.0 * temp_factor - term);
}
term = temp_sum;
}
