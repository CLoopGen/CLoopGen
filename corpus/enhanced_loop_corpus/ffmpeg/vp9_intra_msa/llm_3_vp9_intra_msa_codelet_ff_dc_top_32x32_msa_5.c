#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dst_stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t **indirect_access = (uint8_t**)malloc(32 * sizeof(uint8_t*));
    if (!indirect_access) return;
    uint8_t *cur = dst;
    for (row = 0; row < 32; row++) {
        indirect_access[row] = cur;
        cur += dst_stride;
    }
    for (row = 16; row--;) {
        // Simulate strided access using indirect pointers: access every second entry
        volatile uint8_t dummy1 = *indirect_access[2 * row];
        volatile uint8_t dummy2 = *indirect_access[2 * row + 1];
    }
    free(indirect_access);
}
