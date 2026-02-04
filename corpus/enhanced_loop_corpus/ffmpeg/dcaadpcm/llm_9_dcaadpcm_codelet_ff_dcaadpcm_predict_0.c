#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *input;
extern int i;
extern  int16_t *coeff;
extern int64_t pred;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        int32_t temp1 = input[3 - i];
        int32_t temp2 = input[1 - i];
        pred += (int64_t)temp1 * coeff[i];
        pred += (int64_t)temp2 * coeff[3 - i];
    }
}
