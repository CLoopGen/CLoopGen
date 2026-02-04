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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < maxc; i += 2) {
        uint32_t nc = (cnt[i] >> 1) + 1;
        cnt[i] = nc;
        totfr += nc;
        // Handle boundary condition for odd-sized arrays
        if (i + 1 < maxc) {
            uint32_t nc_next = (cnt[i + 1] >> 1) + 1;
            cnt[i + 1] = nc_next;
            totfr += nc_next;
        }
    }
}
