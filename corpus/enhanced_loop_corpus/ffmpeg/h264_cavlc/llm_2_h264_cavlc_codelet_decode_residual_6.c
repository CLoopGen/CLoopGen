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
    // Variant 1: Consecutive memory access by reversing the scan order and accessing block in increasing index order
    // We assume that *scantable initially points to the end of a table and decrements, so we convert to forward traversal.
    int idx = total_coeff - 1;
    for (; i < total_coeff; i++, idx--) {
        int pos = scantable[idx];  // Indirect but consecutive read from scantable
        ((int32_t *)block)[pos] = ((int)(level[i] * qmul[pos] + 32)) >> 6;
    }
}
