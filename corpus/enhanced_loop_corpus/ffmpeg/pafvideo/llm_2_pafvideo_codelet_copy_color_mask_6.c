#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern uint8_t color;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering operations to write to contiguous addresses
    uint8_t *d = dst;
    int w = width;
    uint8_t m = mask;
    uint8_t c = color;
    
    // Process both conditions with combined offset calculation to enable consecutive access
    for (i = 0; i < 4; i++) {
        if (m & (1 << (7 - i))) {
            d[i] = c;
        }
        if (m & (1 << (3 - i))) {
            d[i + w] = c;
        }
    }
}
