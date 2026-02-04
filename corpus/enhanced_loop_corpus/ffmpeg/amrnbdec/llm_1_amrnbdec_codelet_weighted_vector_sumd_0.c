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
    int j, chunk_size = 16;
    for (j = 0; j < length; j += chunk_size) {
        for (i = j; i < j + chunk_size && i < length; i++)
            out[i] = weight_coeff_a * in_a[i] + weight_coeff_b * in_b[i];
    }
}
