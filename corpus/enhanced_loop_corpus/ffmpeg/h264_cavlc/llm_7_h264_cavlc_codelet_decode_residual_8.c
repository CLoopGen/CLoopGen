#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern  uint32_t *qmul;
extern int level[16];
extern int total_coeff;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset;
    int16_t *block_ptr = (int16_t *)block;
    for (; i < total_coeff; i++) {
        scantable--;
        offset = *scantable;
        // Introduce artificial WAW and WAR dependency by reordering computation
        int product = level[i] * qmul[offset];
        int result = (product + 32) >> 6;
        block_ptr[offset] = result;
        block_ptr[offset] += 0; // Artificial WAW dependency: redundant write with no effect
    }
}
