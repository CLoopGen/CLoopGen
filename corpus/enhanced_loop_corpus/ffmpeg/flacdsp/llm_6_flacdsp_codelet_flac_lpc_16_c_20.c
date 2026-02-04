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
    int temp_sum = 0;
    for (j = 0; j < pred_order; j++)
        temp_sum += coeffs[j] * (unsigned int)decoded[j];
    sum = temp_sum;
}
