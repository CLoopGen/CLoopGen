#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *decoded;
extern  int coeffs[32];
extern int pred_order;
extern int j;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (j = 0; j < pred_order; j++) {
        int coeff_val = coeffs[j];
        int decoded_val = (unsigned int)decoded[j];
        if (coeff_val == 0) continue;
        sum += coeff_val * decoded_val;
    }
}
