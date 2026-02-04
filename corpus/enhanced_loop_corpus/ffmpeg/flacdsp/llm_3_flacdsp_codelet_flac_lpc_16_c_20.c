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
    // Variant 2: Reverse sequential access (access arrays from high to low index)
    for (j = pred_order - 1; j >= 0; j--)
        sum += coeffs[j] * (unsigned int)decoded[j];
}
