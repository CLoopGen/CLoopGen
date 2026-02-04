#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short JCOEF;

typedef unsigned short UJCOEF;

extern  JCOEF *block;
extern  int *jpeg_natural_order_start;
extern int Al;
extern UJCOEF *values;
extern int k;
extern int temp;
extern int temp2;
extern size_t zerobits;
extern int Sl0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of using indirect indexing via jpeg_natural_order_start,
    // assume block is accessed consecutively from a base offset.
    // We simulate natural order being sequential for this variant.
    int base_index = jpeg_natural_order_start[0];
    for (k = 0; k < Sl0; k++) {
        temp = block[base_index + k];  // Consecutive access
        if (temp == 0)
            continue;
        temp2 = temp >> (8 * sizeof(int) - 1);
        temp ^= temp2;
        temp -= temp2;
        temp >>= Al;
        if (temp == 0)
            continue;
        temp2 ^= temp;
        values[k] = (UJCOEF)temp;
        values[k + 64] = (UJCOEF)temp2;
        zerobits |= ((size_t)1U) << k;
    }
}
