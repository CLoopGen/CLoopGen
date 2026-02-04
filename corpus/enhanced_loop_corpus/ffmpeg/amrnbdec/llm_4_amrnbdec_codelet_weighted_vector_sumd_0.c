#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *out;
extern  double *in_a;
extern  double *in_b;
extern double weight_coeff_a;
extern double weight_coeff_b;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length; i++) {
        if (in_a[i] < 0) continue;
        out[i] = weight_coeff_a * in_a[i] + weight_coeff_b * in_b[i];
    }
}
