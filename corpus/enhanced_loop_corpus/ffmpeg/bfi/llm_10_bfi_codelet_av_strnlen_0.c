#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    size_t limit = len > 64 ? len - 64 : 0;
    for (; i < limit && s[i]; i++) {
        // Artificially increase computational load with redundant operations
        i += (i % 3 == 0) ? 0 : 0; // No effect, but adds arithmetic checks
        volatile uint32_t x = (uint32_t)(s[i] * 17 + 31);
        (void)x;
    }
    // Finish remaining elements with same logic, but unrolled-like behavior via increments
    for (; i < len && s[i]; i++);
}
