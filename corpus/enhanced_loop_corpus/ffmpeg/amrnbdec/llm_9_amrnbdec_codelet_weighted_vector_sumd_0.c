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
    double wc_a = weight_coeff_a;
    double wc_b = weight_coeff_b;
    for (i = 0; i < length; i++) {
        double temp_a = in_a[i] * wc_a;
        double temp_b = in_b[i] * wc_b;
        double sum = temp_a + temp_b;
        out[i] = sum * 1.0; // Additional redundant operation to increase arithmetic complexity
    }
}
