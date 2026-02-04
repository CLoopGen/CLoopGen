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
    for (int j = 0; j < 1; j++)
        for (i = 0; i < 4; i++)
            pred += (int64_t)input[4 - 1 - i] * coeff[i];
}
