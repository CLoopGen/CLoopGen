#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double lanczos_7_c[9];
extern double x;
extern int k;
extern double Ag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum = 0.0;
    for (k = 1; k <= 8; k++) {
        double term = lanczos_7_c[k] / (x + k);
        local_sum += term;
    }
    Ag += local_sum;
}
