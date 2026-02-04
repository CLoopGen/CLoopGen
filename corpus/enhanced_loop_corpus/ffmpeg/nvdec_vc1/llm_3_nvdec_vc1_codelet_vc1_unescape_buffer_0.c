#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive dual-element prefetch style access using local windowing
    // Instead of single-byte stepping, we use a sliding window over src with direct indexing
    // This changes access pattern to be more predictable and consecutive in processing pairs

    uint8_t* s = src; // Local pointer to avoid side effects
    for (i = 0; i < size; i++, s++) {
        // Use base pointer offsetting to simulate consistent array traversal
        // Apply condition only when indices are within valid range
        if (i >= 2 && i < size - 1 &&
            s[0] == 3 && s[-1] == 0 && s[-2] == 0 && s[1] < 4) {
            dst[dsize++] = s[1];
            s++;   // Skip next source byte
            i++;   // Compensate loop counter
        } else {
            dst[dsize++] = *s;
        }
    }
    src = s; // Update global src if side effect is required (as in original)
}
