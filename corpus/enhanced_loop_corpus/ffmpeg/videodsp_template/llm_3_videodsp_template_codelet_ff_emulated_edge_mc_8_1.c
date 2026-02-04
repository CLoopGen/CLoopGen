#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int block_w;
extern int x;
extern int end_x;
extern uint8_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive write with reverse traversal (backward access pattern)
    int start = end_x;
    int count = block_w - end_x;
    for (int i = 0; i < count; i++) {
        bufp[start + i] = bufp[end_x - 1];
    }
}
