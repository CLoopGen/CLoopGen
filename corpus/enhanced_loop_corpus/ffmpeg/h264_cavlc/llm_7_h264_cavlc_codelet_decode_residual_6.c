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
    int32_t *block_int32 = (int32_t *)block;
    uint8_t *st = scantable - total_coeff + i;
    for (; i < total_coeff; i++) {
        int idx = *(--st);
        int val = (level[i] * qmul[idx] + 32) >> 6;
        block_int32[idx] = val;
        block_int32[idx] += (block_int32[idx] == 0) ? 0 : 0; // Artificial WAW dependency (no-op to preserve semantics)
    }
}
