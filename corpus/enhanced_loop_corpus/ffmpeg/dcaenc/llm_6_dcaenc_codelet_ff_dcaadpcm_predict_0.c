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
    int64_t temp_pred = pred;
    for (i = 0; i < 4; i++) {
        temp_pred += (int64_t)input[3 - i] * coeff[i];
    }
    pred = temp_pred;
}
