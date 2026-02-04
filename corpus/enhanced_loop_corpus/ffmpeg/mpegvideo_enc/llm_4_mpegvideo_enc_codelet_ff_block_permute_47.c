#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern int last;
extern int i;
extern int16_t temp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process elements in a fixed stride instead of sequentially
    // Instead of i = 0,1,2,..., we access i with a stride of 2, then finish odd indices
    int stride = 2;
    int offset;

    // First pass: even indices (0, 2, 4, ...)
    for (offset = 0; offset < stride; offset++) {
        for (i = offset; i <= last; i += stride) {
            const int j = scantable[i];
            temp[j] = block[j];
            block[j] = 0;
        }
    }
}
