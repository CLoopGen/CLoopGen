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
    // Variant 1: Consecutive memory access with reversed input traversal
    // Instead of accessing input[3], input[2], ..., we reverse the order to input[0], input[1], ...
    // and adjust coefficient indexing accordingly to preserve computation semantics.
    for (i = 0; i < 4; i++)
        pred += (int64_t)input[i] * coeff[4 - 1 - i];
}
