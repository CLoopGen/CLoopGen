#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern  uint8_t *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with reverse traversal
    // Access pattern: a is accessed every 1 byte but traversed in reverse order
    // r is filled in normal order, but a is read from end to beginning using strided index
    for (i = 0; i < 256; ++i) {
        int rev_index = 31 - (i >> 3);  // Reverse the block index for a (assuming a has at least 32 bytes)
        r[i] = 1 & (a[rev_index] >> (i & 7));
    }
}
