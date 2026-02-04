#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int last_index;
extern  uint8_t *scantable;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect access via pointer arithmetic with precomputed indices
    int16_t *block_ptr = block;
    uint8_t *scan_ptr = scantable + last_index;
    for (last_index = 63; last_index >= 0; last_index--, scan_ptr--) {
        if (*(block_ptr + *scan_ptr))
            break;
    }
}
