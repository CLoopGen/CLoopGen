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
    for (i = 0; i < 4; ++i) {
        int32_t in_val = input[3 - i];
        if (in_val > 0) {
            pred += (int64_t)in_val * coeff[i];
        } else {
            pred -= (int64_t)in_val * coeff[i];
        }
    }
}
