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
    for (j = 0; j < pred_order && pred_order > 0; j++) {
        unsigned int temp = (unsigned int)decoded[j];
        if (temp & 1) {
            sum += coeffs[j] * temp;
        } else {
            sum -= coeffs[j];
        }
    }
}
