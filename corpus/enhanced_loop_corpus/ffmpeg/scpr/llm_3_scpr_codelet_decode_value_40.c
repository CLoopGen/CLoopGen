#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *cnt;
extern uint32_t maxc;
extern uint32_t totfr;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array (simulated via stride reversal)
    // Simulate indirect access by traversing the array from both ends toward the center
    for (i = 0; i < maxc; i++) {
        int idx = (i % 2 == 0) ? (i / 2) : (maxc - 1 - i / 2); // Interleave front and back
        if (idx >= maxc) continue; // Safety check in case of miscalculation
        uint32_t nc = (cnt[idx] >> 1) + 1;
        cnt[idx] = nc;
        totfr += nc;
    }
}
