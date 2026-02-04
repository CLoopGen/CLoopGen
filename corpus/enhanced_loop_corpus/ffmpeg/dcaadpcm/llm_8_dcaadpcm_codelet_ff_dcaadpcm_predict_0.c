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
    for (i = 0; i < 8; i += 2) {
        pred += (int64_t)input[7 - i] * coeff[i % 4];
        pred += (int64_t)input[7 - (i + 1)] * coeff[(i + 1) % 4];
    }
}
