#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — process every 2nd element first, then handle remaining offset in a second phase is not allowed per constraints.
    // Instead, apply a strided pattern within the loop: access with step size 2 across all arrays, updating only even indices
    for (; i <= size - 2; i += 2) {
        int idx = i;  // Use computed index to enforce strided access pattern: idx, idx+2, etc.
        dst[idx] = r = (((((r) + (last[idx])) >> 1) + (src[idx])) & 255);
        if (idx + 2 < size) {
            dst[idx + 2] = g = (((((g) + (last[idx + 2])) >> 1) + (src[idx + 2])) & 255);
        }
        if (idx + 4 < size) {
            dst[idx + 4] = b = (((((b) + (last[idx + 4])) >> 1) + (src[idx + 4])) & 255);
        }
        if (idx + 6 < size) {
            dst[idx + 6] = a = (((((a) + (last[idx + 6])) >> 1) + (src[idx + 6])) & 255);
        }
        // Simulate propagation by skipping ahead in stride; note: r,g,b,a still carry forward
    }
}
