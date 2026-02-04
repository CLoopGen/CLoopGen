#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern  int linesize;
extern int trans;
extern  int w;
extern int y_end;
extern int is_trans;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic and unrolling
    uint8_t *ptr = &buf[linesize * y_end];
    int i = 0;
    // Process two elements per iteration for better locality and unrolled-like behavior
    for (; i < w - 1; i += 2) {
        if (ptr[i] != trans || ptr[i + 1] != trans) {
            is_trans = 0;
            break;
        }
    }
    // Handle remaining element if w is odd
    for (; i < w; i++) {
        if (ptr[i] != trans) {
            is_trans = 0;
            break;
        }
    }
}
